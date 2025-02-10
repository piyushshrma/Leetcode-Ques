class Solution {
public:

    bool even(int num){
        string s=to_string(num);
        return s.size()%2==0;
    }
    int findNumbers(vector<int>& nums) {
        int count=0;
        for(int i=0; i<nums.size(); i++){
            if(even(nums[i])){count++;}
        }
        return count;
    }
};



// class Solution {
// public:
//     bool even(int num){
//         int digitCount = 0;
//         if (num == 0) {
//             digitCount = 1;  // special case for 0 as it has 1 digit
//         } else {
//             while (num != 0) {
//                 num /= 10;
//                 digitCount++;
//             }
//         }
//         return digitCount % 2 == 0;
//     }

//     int findNumbers(vector<int>& nums) {
//         int count = 0;
//         for (int i = 0; i < nums.size(); i++) {
//             if (even(nums[i])) {
//                 count++;
//             }
//         }
//         return count;
//     }
// };
