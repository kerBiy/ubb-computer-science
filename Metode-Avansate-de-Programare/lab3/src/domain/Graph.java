package domain;

import java.util.*;

public class Graph {
    private final int size;
    private final List<Friendship> friendships;
    private final Map<Long, List<Long>> adjList = new HashMap<>();

    public Graph(int size, List<Friendship> friendships) {
        this.size = size;
        this.friendships = friendships;
        buildAdjacencyList();
    }

    private void buildAdjacencyList() {
        for (Friendship friendship : friendships) {
            adjList.computeIfAbsent(friendship.getUser1(), _ -> new ArrayList<>()).add(friendship.getUser2());
            adjList.computeIfAbsent(friendship.getUser2(), _ -> new ArrayList<>()).add(friendship.getUser1());
        }
    }

    // Finds the number of connected components
    public int findStronglyConnectedComponents() {
        Set<Long> visited = new HashSet<>();
        int componentCount = 0;

        for (Long user : adjList.keySet()) {
            if (!visited.contains(user)) {
                componentCount++;
                dfs(user, visited);
            }
        }
        return componentCount;
    }

    private void dfs(Long user, Set<Long> visited) {
        visited.add(user);
        for (Long neighbor : adjList.getOrDefault(user, Collections.emptyList())) {
            if (!visited.contains(neighbor)) {
                dfs(neighbor, visited);
            }
        }
    }

    // Finds the longest path in the largest connected component
    public List<Long> findLongestPathInLargestComponent() {
        Set<Long> visited = new HashSet<>();
        List<Long> longestPath = new ArrayList<>();

        for (Long user : adjList.keySet()) {
            if (!visited.contains(user)) {
                List<Long> component = new ArrayList<>();
                dfsCollectComponent(user, visited, component);

                List<Long> currentLongestPath = findLongestPathInComponent(component);
                if (currentLongestPath.size() > longestPath.size()) {
                    longestPath = currentLongestPath;
                }
            }
        }
        return longestPath;
    }

    private void dfsCollectComponent(Long user, Set<Long> visited, List<Long> component) {
        visited.add(user);
        component.add(user);
        for (Long neighbor : adjList.getOrDefault(user, Collections.emptyList())) {
            if (!visited.contains(neighbor)) {
                dfsCollectComponent(neighbor, visited, component);
            }
        }
    }

    private List<Long> findLongestPathInComponent(List<Long> component) {
        if (component.isEmpty()) {
            return new ArrayList<>();
        }

        Long farthestNode = bfsFindFarthest(component.getFirst());
        return bfsPath(farthestNode);
    }

    private Long bfsFindFarthest(Long start) {
        Queue<Long> queue = new LinkedList<>();
        queue.add(start);
        Set<Long> visited = new HashSet<>();
        visited.add(start);

        Long farthest = start;
        while (!queue.isEmpty()) {
            farthest = queue.poll();
            for (Long neighbor : adjList.getOrDefault(farthest, Collections.emptyList())) {
                if (!visited.contains(neighbor)) {
                    visited.add(neighbor);
                    queue.add(neighbor);
                }
            }
        }
        return farthest;
    }

    private List<Long> bfsPath(Long start) {
        Queue<Long> queue = new LinkedList<>();
        Map<Long, Long> parentMap = new HashMap<>();
        queue.add(start);
        parentMap.put(start, null);

        Long farthest = start;
        while (!queue.isEmpty()) {
            farthest = queue.poll();
            for (Long neighbor : adjList.getOrDefault(farthest, Collections.emptyList())) {
                if (!parentMap.containsKey(neighbor)) {
                    parentMap.put(neighbor, farthest);
                    queue.add(neighbor);
                }
            }
        }

        List<Long> path = new ArrayList<>();
        for (Long node = farthest; node != null; node = parentMap.get(node)) {
            path.add(node);
        }
        Collections.reverse(path);
        return path;
    }
}