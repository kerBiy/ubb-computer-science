package ubb.map.examenpractic.service;

import ubb.map.examenpractic.domain.City;
import ubb.map.examenpractic.domain.TrainStation;
import ubb.map.examenpractic.repository.CityRepository;
import ubb.map.examenpractic.repository.TrainStationRepository;
import ubb.map.examenpractic.utils.Observable;

import java.util.*;
import java.util.concurrent.ConcurrentHashMap;
import java.util.stream.Collectors;

public class Service extends Observable {
    private final CityRepository cityRepository;
    private final TrainStationRepository trainStationRepository;
    private final Map<String, Integer> activeFilters = new ConcurrentHashMap<>();
    private final Integer PRICE_PER_STATIE = 10;

    public Service(CityRepository cityRepository, TrainStationRepository trainStationRepository) {
        this.cityRepository = cityRepository;
        this.trainStationRepository = trainStationRepository;
    }

    public List<String> getCityNames() {
        List<City> cities = (List<City>) cityRepository.findAll();

        return cities.stream()
                .map(City::getName)
                .collect(Collectors.toList());
    }

    public List<String> searchRoutes(String departureCityName, String destinationCityName, boolean directRoutesOnly) {
        List<City> cities = (List<City>) cityRepository.findAll();
        Map<String, String> cityNameToId = cities.stream()
                .collect(Collectors.toMap(City::getName, City::getId));

        String departureCityId = cityNameToId.get(departureCityName);
        String destinationCityId = cityNameToId.get(destinationCityName);

        if (departureCityId == null || destinationCityId == null) {
            return List.of("Invalid city names provided.");
        }

        List<TrainStation> trainStations = (List<TrainStation>) trainStationRepository.findAll();

        if (directRoutesOnly) {
            return trainStations.stream()
                    .filter(route -> route.getDepartureCityId().equals(departureCityId) && route.getDestinationCityId().equals(destinationCityId))
                    .map(route -> String.format("%s -> %s -> %s", departureCityName, route.getId(), destinationCityName))
                    .collect(Collectors.toList());
        } else {
            List<String> routes = new ArrayList<>();
            findRoutesWithChanges(departureCityId, destinationCityId, trainStations, new LinkedHashSet<>(), routes, cityNameToId, new LinkedList<>());
            return routes;
        }
    }

    private void findRoutesWithChanges(String currentCityId, String destinationCityId, List<TrainStation> trainStations, Set<String> visited, List<String> routes, Map<String, String> cityNameToId, LinkedList<String> currentRoute) {
        if (visited.contains(currentCityId)) {
            return;
        }

        visited.add(currentCityId);

        for (TrainStation station : trainStations) {
            if (station.getDepartureCityId().equals(currentCityId)) {
                currentRoute.add(cityNameToId.entrySet().stream()
                        .filter(entry -> entry.getValue().equals(currentCityId))
                        .map(Map.Entry::getKey)
                        .findFirst().orElse(currentCityId));
                currentRoute.add(station.getId());

                if (station.getDestinationCityId().equals(destinationCityId)) {
                    currentRoute.add(cityNameToId.entrySet().stream()
                            .filter(entry -> entry.getValue().equals(destinationCityId))
                            .map(Map.Entry::getKey)
                            .findFirst().orElse(destinationCityId));
                    routes.add(String.join(" -> ", currentRoute));
                    currentRoute.removeLast();
                } else {
                    findRoutesWithChanges(station.getDestinationCityId(), destinationCityId, trainStations, new LinkedHashSet<>(visited), routes, cityNameToId, currentRoute);
                }

                currentRoute.removeLast();
                currentRoute.removeLast();
            }
        }

        visited.remove(currentCityId);
    }

    public void registerFilter(String departureCity, String destinationCity) {
        String key = departureCity + "->" + destinationCity;
        activeFilters.put(key, activeFilters.getOrDefault(key, 0) + 1);
        notifyObservers();
    }

    public void unregisterFilter(String departureCity, String destinationCity) {
        String key = departureCity + "->" + destinationCity;
        activeFilters.put(key, activeFilters.getOrDefault(key, 0) - 1);
        if (activeFilters.get(key) <= 0) {
            activeFilters.remove(key);
        }
        notifyObservers();
    }

    public int getActiveFilterCount(String departureCity, String destinationCity) {
        return activeFilters.getOrDefault(departureCity + "->" + destinationCity, 0);
    }

    public int calculatePrice(String route) {
        List<TrainStation> trainStations = (List<TrainStation>) trainStationRepository.findAll();
        Set<String> trainIds = trainStations.stream()
                .map(TrainStation::getId)
                .collect(Collectors.toSet());

        long stationCount = Arrays.stream(route.split("->"))
                .filter(segment -> !segment.trim().isEmpty())
                .filter(segment -> !trainIds.contains(segment.trim()))
                .count();
        return (int) stationCount * PRICE_PER_STATIE - PRICE_PER_STATIE;
    }
}
