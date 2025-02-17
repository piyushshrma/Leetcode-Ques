class Solution {
public:
    int numTilePossibilities(string tiles) {
        int count[26] = {}; // Initialize array to store the count of each letter
      
        // Count the occurrences of each letter in the tiles string
        for (char tile : tiles) {
            ++count[tile - 'A']; // Increase the count for the corresponding letter
        }
      
        // Define the recursive depth-first search function that calculates the possibilities
        function<int(int* count)> dfs = [&](int* count) -> int {
            int result = 0;
            // Iterate over all possible tile characters
            for (int i = 0; i < 26; ++i) {
                if (count[i] > 0) { // If the tile character is available
                    ++result; // This is a valid possibility by adding one tile
                    --count[i]; // Use one tile of the current character to explore further
                    result += dfs(count); // Explore further and add the result
                    ++count[i]; // Backtrack and add the tile back
                }
            }
            return result; // Return the total possibilities at this recursion level
        };
      
        // Start the recursion with the initial count and return the result
        return dfs(count);
    }
};