class Solution {
public:
    int countServers(std::vector<std::vector<int>>& grid) {
        int rowCount = grid.size();            // number of rows in the grid
        int colCount = grid[0].size();         // number of columns in the grid
      
        // Create a vector to store the count of servers in each row and column
        std::vector<int> serversInRow(rowCount, 0);
        std::vector<int> serversInColumn(colCount, 0);

        // Calculate the number of servers in each row and column
        for (int i = 0; i < rowCount; ++i) {
            for (int j = 0; j < colCount; ++j) {
                if (grid[i][j]) {  // if there is a server at position (i, j)
                    ++serversInRow[i];      // increment the count for the row
                    ++serversInColumn[j];   // increment the count for the column
                }
            }
        }
      
        // Count the number of servers that can communicate with at least one other server
        int serverCount = 0;  // variable to keep track of the total count
        for (int i = 0; i < rowCount; ++i) {
            for (int j = 0; j < colCount; ++j) {
                // A server at (i, j) can communicate if there are other servers in the same
                // row or column (hence, count will be more than 1 for that row or column).
                if (grid[i][j] && (serversInRow[i] > 1 || serversInColumn[j] > 1)) {
                    serverCount++;
                }
            }
        }
      
        return serverCount;  // Return the total count of servers that can communicate
    }
};