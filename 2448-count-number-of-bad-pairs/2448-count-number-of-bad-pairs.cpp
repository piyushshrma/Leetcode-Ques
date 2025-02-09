#include <unordered_map>
#include <vector>

class Solution {
public:
    // Function to count the number of 'bad' pairs in the array
    // A pair (i, j) is considered 'bad' if i < j and j - i != nums[j] - nums[i]
    long long countBadPairs(std::vector<int>& nums) {
        unordered_map<int, int> count_map; // Map to store the frequency of difference values
        long long bad_pairs_count = 0; // Initialize the count of bad pairs to 0
      
        // Iterate over the elements in nums
        for (int i = 0; i < nums.size(); ++i) {
            int diff = i - nums[i]; // Calculate the difference between index and value
          
            // The total number of pairs with elements before index i is i
            // Subtract the count of the number of 'good' pairs (where the diff is the same)
            bad_pairs_count += i - count_map[diff];
          
            // Increment the count of the current difference in the map
            ++count_map[diff];
        }
      
        // Return the final count of bad pairs
        return bad_pairs_count;
    }
};