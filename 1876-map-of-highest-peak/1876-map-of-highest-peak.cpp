class Solution {
public:
    // Define directions for exploring adjacent cells: up, right, down, left.
    const vector<int> dirs{-1, 0, 1, 0, -1};

    // Function to calculate the highest peak elevation for each cell.
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();      // Number of rows.
        int n = isWater[0].size();   // Number of columns.
        vector<vector<int>> ans(m, vector<int>(n));
        queue<pair<int, int>> q;     // Queue to perform a breadth-first search.
      
        // Initialize the answer matrix and enqueue all water cells.
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans[i][j] = isWater[i][j] - 1; // Water cells become 0, land cells -1.
                if (ans[i][j] == 0) {
                    // If the cell is water, add it to the queue for BFS.
                    q.emplace(i, j);
                }
            }
        }
      
        // Perform breadth-first search to determine elevation of each cell.
        while (!q.empty()) {
            auto [i, j] = q.front(); // Get the front cell from the queue.
            q.pop();
            for (int k = 0; k < 4; ++k) { // Explore all 4 adjacent cells.
                int x = i + dirs[k];    // Calculate the new x-coordinate.
                int y = j + dirs[k + 1];// Calculate the new y-coordinate.
                // Check if the new coordinates are in bounds and the cell is not yet visited.
                if (x >= 0 && x < m && y >= 0 && y < n && ans[x][y] == -1) {
                    // Set the elevation of the cell to be one more than current cell's elevation.
                    ans[x][y] = ans[i][j] + 1;
                    // Add this cell to the queue to continue BFS from here.
                    q.emplace(x, y);
                }
            }
        }
        return ans; // Return the elevation matrix.
    }
};
