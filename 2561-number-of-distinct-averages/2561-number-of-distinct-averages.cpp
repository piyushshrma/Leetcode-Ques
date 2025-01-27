class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        // Sort the input vector in non-decreasing order.
        sort(nums.begin(), nums.end());
      
        // Initialize a count array of size 201 to store 
        // the frequency of the sum of pairs.
        int countArray[201] = {};
      
        // Obtain the size of the input vector.
        int numElements = nums.size();
      
        // Initialize a variable to store the count of distinct averages.
        int distinctCount = 0;
      
        // Loop through the first half of the vector as we are creating pairs
        // that consist of one element from the first half and one from the second.
        for (int i = 0; i < numElements / 2; ++i) {
            // Calculate the sum of the current pair: the i-th element and its corresponding
            // element in the second half of the array (mirror position regarding the center).
            int pairSum = nums[i] + nums[numElements - i - 1];
          
            // If this sum appears for the first time, increase the distinct count.
            if (++countArray[pairSum] == 1) {
                ++distinctCount;
            }
        }
      
        // Return the count of distinct averages.
        return distinctCount;
    }
};