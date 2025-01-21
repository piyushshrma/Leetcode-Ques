class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int missingCount = 0;  // How many numbers we've missed so far
        int current = 1;       // Start checking from number 1
        int idx = 0;           // Pointer for the array

        // Keep checking until we find k missing numbers
        while (missingCount < k) {
            // If current number is in the array, move to the next number
            if (idx < arr.size() && arr[idx] == current) {
                idx++;
            } else {
                // Otherwise, it's missing, so increment the missing count
                missingCount++;
            }
            current++;  // Check the next number
        }

        return current - 1;  // The last checked number is the k-th missing number
    }
};