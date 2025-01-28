class Solution {
public:
    int findMaxFish(std::vector<std::vector<int>>& grid) {
        int numRows = grid.size();
        int numCols = grid[0].size();
        int maxFishCount = 0;

        // Depth-first search function to search for connected fishes.
        std::function<int(int, int)> depthFirstSearch = [&](int row, int col) -> int {
            int fishCount = grid[row][col];
            grid[row][col] = 0; // Mark as visited by setting to 0.

            // Directions: up, right, down, left
            int directions[5] = {-1, 0, 1, 0, -1};
            for (int k = 0; k < 4; ++k) {
                int newRow = row + directions[k];
                int newCol = col + directions[k + 1];

                // Check if the new coordinates are valid and not visited.
                if (newRow >= 0 && newRow < numRows && newCol >= 0 && newCol < numCols && grid[newRow][newCol]) {
                    fishCount += depthFirstSearch(newRow, newCol); // Recurse.
                }
            }
            return fishCount;
        };

        // Iterate over each cell in the grid.
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                // If cell is not visited and there are fishes, perform DFS.
                if (grid[i][j]) {
                    maxFishCount = std::max(maxFishCount, depthFirstSearch(i, j));
                }
            }
        }
        return maxFishCount; // Return the maximum number of fishes in a connected region.
    }
};