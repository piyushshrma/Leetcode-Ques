class Solution {
public:
    int findLHS(vector<int>& nums) {
       sort(nums.begin(), nums.end());
       map<int, int> mp;
        for(auto& i : nums){
            mp[i]++;
        }
        int maxLen = 0;

        for(auto& i : mp){
            if(mp.count(i.first+1)){
                int len = i.second + mp[i.first+1];
                maxLen=max(len,maxLen);
            }
        }
        return maxLen;
    }
};