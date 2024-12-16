package org.university.socialapp.Domain;

import java.util.*;

public class Graph {
    private final int size;
    private final List<Friendship> friendships;
    private final Map<String, List<String>> adjList = new HashMap<>();

    public Graph(int size, List<Friendship> friendships) {
        this.size = size;
        this.friendships = friendships;
        buildAdjacencyList();
    }

    private void buildAdjacencyList() {
        for (Friendship friendship : friendships) {
            adjList.computeIfAbsent(friendship.getUser1(), key -> new ArrayList<>()).add(friendship.getUser2());
            adjList.computeIfAbsent(friendship.getUser2(), key -> new ArrayList<>()).add(friendship.getUser1());
        }
    }

    // Finds the number of connected components
    public int findStronglyConnectedComponents() {
        Set<String> visited = new HashSet<>();
        int componentCount = 0;

        for (String user : adjList.keySet()) {
            if (!visited.contains(user)) {
                componentCount++;
                dfs(user, visited);
            }
        }
        return componentCount;
    }

    private void dfs(String user, Set<String> visited) {
        visited.add(user);
        for (String neighbor : adjList.getOrDefault(user, Collections.emptyList())) {
            if (!visited.contains(neighbor)) {
                dfs(neighbor, visited);
            }
        }
    }

    // Finds the longest path in the largest connected component
    public List<String> findLongestPathInLargestComponent() {
        Set<String> visited = new HashSet<>();
        List<String> longestPath = new ArrayList<>();

        for (String user : adjList.keySet()) {
            if (!visited.contains(user)) {
                List<String> component = new ArrayList<>();
                dfsCollectComponent(user, visited, component);

                List<String> currentLongestPath = findLongestPathInComponent(component);
                if (currentLongestPath.size() > longestPath.size()) {
                    longestPath = currentLongestPath;
                }
            }
        }
        return longestPath;
    }

    private void dfsCollectComponent(String user, Set<String> visited, List<String> component) {
        visited.add(user);
        component.add(user);
        for (String neighbor : adjList.getOrDefault(user, Collections.emptyList())) {
            if (!visited.contains(neighbor)) {
                dfsCollectComponent(neighbor, visited, component);
            }
        }
    }

    private List<String> findLongestPathInComponent(List<String> component) {
        if (component.isEmpty()) {
            return new ArrayList<>();
        }

        String farthestNode = bfsFindFarthest(component.getFirst());
        return bfsPath(farthestNode);
    }

    private String bfsFindFarthest(String start) {
        Queue<String> queue = new LinkedList<>();
        queue.add(start);
        Set<String> visited = new HashSet<>();
        visited.add(start);

        String farthest = start;
        while (!queue.isEmpty()) {
            farthest = queue.poll();
            for (String neighbor : adjList.getOrDefault(farthest, Collections.emptyList())) {
                if (!visited.contains(neighbor)) {
                    visited.add(neighbor);
                    queue.add(neighbor);
                }
            }
        }
        return farthest;
    }

    private List<String> bfsPath(String start) {
        Queue<String> queue = new LinkedList<>();
        Map<String, String> parentMap = new HashMap<>();
        queue.add(start);
        parentMap.put(start, null);

        String farthest = start;
        while (!queue.isEmpty()) {
            farthest = queue.poll();
            for (String neighbor : adjList.getOrDefault(farthest, Collections.emptyList())) {
                if (!parentMap.containsKey(neighbor)) {
                    parentMap.put(neighbor, farthest);
                    queue.add(neighbor);
                }
            }
        }

        List<String> path = new ArrayList<>();
        for (String node = farthest; node != null; node = parentMap.get(node)) {
            path.add(node);
        }
        Collections.reverse(path);
        return path;
    }
}