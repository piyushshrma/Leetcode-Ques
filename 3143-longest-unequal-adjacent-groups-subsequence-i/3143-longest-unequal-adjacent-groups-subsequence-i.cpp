class Solution {
public:

//     bool help(int i, int j, int k){
//     return i != j && j != k;
// }

    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans;
        int n=words.size();

        if(n==0) return ans;

        ans.push_back(words[0]);
        int lastgrp=groups[0];

        for(int i=1; i<n; i++){
            if(groups[i]!=lastgrp){
                ans.push_back(words[i]);
                lastgrp=groups[i];
            }
        }
        return ans;
    }
};