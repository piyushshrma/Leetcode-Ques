// class Solution {
// public:

//     int digsum(int num){
//         int sum=0;
//         while(num > 0){
//             int rem=num%10;
//             sum+=rem;
//             num=num/10;
//         }
//         return sum;
//     }
//     int maximumSum(vector<int>& nums) {
//         int maxi=-1;
//         for(int i=0; i<nums.size(); i++){
//             for(int j=i+1; j<nums.size(); j++){
//                 if(digsum(nums[i])==digsum(nums[j])){
//                     maxi=max(maxi,nums[i]+nums[j]);
//                 }
//             }
//         }
//         return maxi;
//     }
// };


class Solution {
public:
    // Helper function to calculate the sum of digits
    int digsum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> digitSumMap; // Map to store the largest number for each digit sum
        int maxi = -1; // Variable to store the maximum sum

        // Iterate through the numbers in the list
        for (int num : nums) {
            int sum = digsum(num);

            // If the digit sum is already seen, calculate potential new sum
            if (digitSumMap.count(sum)) {
                maxi = max(maxi, digitSumMap[sum] + num); // Update the max sum
            }

            // Update the map with the maximum number for this digit sum
            digitSumMap[sum] = max(digitSumMap[sum], num);
        }

        return maxi;
    }
};
