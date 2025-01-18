class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        // Get dimensions of the grid
        int rows = grid.size(), cols = grid[0].size();

        // Initialize a 2D vector to keep track of visited cells
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        // Define directions according to the grid value (1: right, 2: left, 3: down, 4: up)
        vector<vector<int>> directions = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        // Queue to perform the BFS, holding pairs of (cell_index, current_cost)
        deque<pair<int, int>> queue;
        queue.push_back({0, 0}); // Start from the top-left corner with 0 cost

        // While there are elements in the queue
        while (!queue.empty()) {
            // Get the front element
            auto current = queue.front();
            queue.pop_front();

            // Calculate row and column from the cell index
            int row = current.first / cols, col = current.first % cols;
            int cost = current.second;

            // If we've reached the bottom-right corner, return the current cost
            if (row == rows - 1 && col == cols - 1) return cost;

            // If the current cell is already visited, skip it
            if (visited[row][col]) continue;

            // Mark the current cell as visited
            visited[row][col] = true;

            // Check all four adjacent cells
            for (int k = 1; k <= 4; ++k) {
                int newRow = row + directions[k][0], newCol = col + directions[k][1];

                // If the new cell is within the grid bounds
                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                    // Calculate the new cell index
                    int newIndex = newRow * cols + newCol;

                    // If the grid indicates the current direction, add to the front of the queue without increasing cost
                    if (grid[row][col] == k)
                        queue.push_front({newIndex, cost});
                    // Otherwise, the direction is not towards the grid arrow - increase the cost and add to the back of the queue
                    else
                        queue.push_back({newIndex, cost + 1});
                }
            }
        }

        // Return -1 if the bottom-right corner could not be reached
        return -1;
    }
};