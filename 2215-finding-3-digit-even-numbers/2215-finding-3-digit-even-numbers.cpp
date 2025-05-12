class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int freq[10] = {};
        for (int digit : digits)
            freq[digit]++;
        vector<int> res;
        for (int i = 1; i <= 9; i++){
            if (freq[i] == 0)
                continue;
            freq[i]--;
            for (int j = 0; j <= 9; j++){
                if (freq[j] == 0)
                    continue;
                freq[j]--;
                for (int k = 0; k <= 8; k += 2){
                    if (freq[k] == 0)
                        continue;
                    res.push_back(i * 100 + j * 10 + k);
                }
                freq[j]++;
            }
            freq[i]++;
        }
        return res;
    }
};


// class Solution {
// public:
//     vector<int> findEvenNumbers(vector<int>& digits) {
//         set<int> numbers;
//         // Iterate through all combinations of 3 digits
//         for (int i = 0; i < digits.size(); i++) {
//             for (int j = 0; j < digits.size(); j++) {
//                 for (int k = 0; k < digits.size(); k++) {
//                     // Check if digits are distinct
//                     if (i != j && i != k && j != k) {
//                         // Check if the last digit is even (k-th digit)
//                         if (digits[k] % 2 == 0) {
//                             // Check if the first digit (i-th digit) is not zero
//                             if (digits[i] != 0) {
//                                 // Form the number by concatenating the digits
//                                 string s = to_string(digits[i]) + to_string(digits[j]) + to_string(digits[k]);
//                                 // Convert the string to an integer and add it to the result
//                                 numbers.insert(stoi(s));
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//         // sort(numbers.begin(), numbers.end());
//         vector<int> ans;
//         for(auto& i : numbers){
//             ans.push_back(i);
//         }
//         return ans;
//     }
// };