class Solution {
public:
    // Returns the first index at which all numbers in a row or column are filled
    // according to the order given in 'arr'.
    int firstCompleteIndex(vector<int>& order, vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        unordered_map<int, pair<int, int>> numberToPosition;

        // Populate a hash map with the number as the key and its position (i, j)
        // in the matrix as the value.
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                numberToPosition[matrix[i][j]] = {i, j};
            }
        }

        // Create a vector to keep track of the count of filled numbers in each row and column.
        vector<int> rowCount(rows, 0), colCount(cols, 0);

        // Iterate through the order vector to simulate filling the matrix.
        for (int k = 0; k < order.size(); ++k) {
            // Get the position of the current number in the order array
            // from the hash map.
            auto [i, j] = numberToPosition[order[k]];

            // Increment the filled numbers count for the respective row and column.
            ++rowCount[i];
            ++colCount[j];

            // If a row or a column is completely filled, return the current index.
            if (rowCount[i] == cols || colCount[j] == rows) {
                return k;
            }
        }

        // The code prior guarantees a result, so this return statement might never be reached.
        // However, it is here as a fail-safe.
        return -1;
    }
};