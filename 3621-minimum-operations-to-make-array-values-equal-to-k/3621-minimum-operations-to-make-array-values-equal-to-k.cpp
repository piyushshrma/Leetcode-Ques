class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        map<int, int> mp;
        for(auto& i : nums){
            mp[i]++;
        }
        int cct=0;
        for(auto& i : mp){
            if(i.first<k){
                return -1;
            }
            if(i.first>k){
                cct++;
            }
        }
        return cct;
    }
};