class Solution {
public:
    string clearStars(string s) {
        int n = s.length();
        vector<int> remove(n, 0);  // To track removed positions

        // A map to store positions for each character
        vector<vector<int>> mp(26);  // We will store indices of characters

        // Step 1: Fill map with character indices
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                // Backspace simulation: pop the last valid character's index
                for (auto& vec : mp) {
                    if (!vec.empty()) {
                        remove[vec.back()] = 1;  // Mark the last index to be removed
                        vec.pop_back();
                        break;  // Remove only the most recent character
                    }
                }
            } else {
                mp[s[i] - 'a'].push_back(i);  // Add index to corresponding character
            }
        }

        // Step 2: Rebuild the final string, skipping removed characters
        string ans = "";
        for (int i = 0; i < n; i++) {
            if (!remove[i] && s[i] != '*') {  // Skip removed and '*' characters
                ans += s[i];
            }
        }

        return ans;
    }
};


// class Solution {
// public:
//     string clearStars(string s) {
//         map<char, vector<int>> mp;

//         for(int idx=0; idx<=s.length(); idx++){
//             if(s[idx]>='a' && s[idx]<='z'){
//                 mp[s[idx]].push_back(idx);
//             }
//             else{
//                 for(auto& i : mp){
//                     i.second.pop_back();
//                 }
//             }
//         }

//         vector<char> leng(26,0);
//         for (auto& entry : mp) {
//         leng[entry.first - 'a'] = entry.first;
//         }

//         string ans="";
//         for(int i=0; i<26; i++){
//             if(leng[i]!=0){
//                 ans.push_back(i+'a');
//             }
//         }
//         return ans;
//     }
// };