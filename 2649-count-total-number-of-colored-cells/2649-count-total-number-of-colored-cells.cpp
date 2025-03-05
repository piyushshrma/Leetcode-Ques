class Solution {
public:
    // Method to calculate the number of colored cells in a pattern
    // Assumes a grid of n by n cells where certain cells are colored
    // based on a given pattern. The pattern rule isn't specified,
    // but the formula 2*n*(n-1) + 1 is applied to determine the result.
    long long coloredCells(int gridSize) {
        // Calculate the number of colored cells according to the given pattern
        // The pattern results in a calculation involving the grid size:
        // 2 multiplied by the grid size (n) and then multiplied by (grid size (n) - 1)
        // Plus 1 for the center or a start cell according to the pattern
        long long numberOfColoredCells = 2LL * gridSize * (gridSize - 1) + 1;

        // Return the calculated number of colored cells
        return numberOfColoredCells;
    }
};