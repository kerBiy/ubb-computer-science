def replace_enclosed_zeros(matrix: list) -> None:
    """
    Replaces all enclosed 0s in a binary matrix with 1s.
    :param matrix: A 2D list representing the binary matrix.
    """
    if not matrix or not matrix[0]:
        return

    rows, cols = len(matrix), len(matrix[0])
    visited = set()

    def dfs(r, c):
        """Marks all 0s connected to the boundary as visited using DFS."""
        if (
            r < 0
            or r >= rows
            or c < 0
            or c >= cols
            or matrix[r][c] != 0
            or (r, c) in visited
        ):
            return
        visited.add((r, c))
        for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            dfs(r + dr, c + dc)

    # Mark all 0s connected to the boundary
    for r in range(rows):
        dfs(r, 0)
        dfs(r, cols - 1)
    for c in range(cols):
        dfs(0, c)
        dfs(rows - 1, c)

    # Replace all unvisited 0s with 1
    for r in range(rows):
        for c in range(cols):
            if matrix[r][c] == 0 and (r, c) not in visited:
                matrix[r][c] = 1


# Test cases
def test_replace_enclosed_zeros():
    matrix = [
        [1, 1, 1, 1, 0, 0, 1, 1, 0, 1],
        [1, 0, 0, 1, 1, 0, 1, 1, 1, 1],
        [1, 0, 0, 1, 1, 1, 1, 1, 1, 1],
        [1, 1, 1, 1, 0, 0, 1, 1, 0, 1],
        [1, 0, 0, 1, 1, 0, 1, 1, 0, 0],
        [1, 1, 0, 1, 1, 0, 0, 1, 0, 1],
        [1, 1, 1, 0, 1, 0, 1, 0, 0, 1],
        [1, 1, 1, 0, 1, 1, 1, 1, 1, 1],
    ]
    expected = [
        [1, 1, 1, 1, 0, 0, 1, 1, 0, 1],
        [1, 1, 1, 1, 1, 0, 1, 1, 1, 1],
        [1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
        [1, 1, 1, 1, 1, 1, 1, 1, 0, 1],
        [1, 1, 1, 1, 1, 1, 1, 1, 0, 0],
        [1, 1, 1, 1, 1, 1, 1, 1, 0, 1],
        [1, 1, 1, 0, 1, 1, 1, 0, 0, 1],
        [1, 1, 1, 0, 1, 1, 1, 1, 1, 1],
    ]
    replace_enclosed_zeros(matrix)
    assert matrix == expected
    print("All tests passed!")


# Run tests
test_replace_enclosed_zeros()

"""
Time Complexity Analysis:
- DFS runs for boundary-connected 0s, visiting each cell at most once: O(n * m).
- Iterating over the matrix again to replace unvisited 0s: O(n * m).
- Overall complexity: O(n * m).

Space Complexity Analysis:
- The `visited` set stores at most O(n * m) elements in the worst case.
- Recursive DFS call stack depth is at most O(n * m) in the worst case.
- Overall space complexity: O(n * m).
"""
