class Solution {
public:

    int check(vector<int>& nums, int i){
        vector<int> newNums;
        for(int j=i; j<nums.size(); j++){
            newNums.push_back(nums[j]);
        }
        map<int, int> mp;
        for(auto& k : newNums){
            mp[k]++;
        }

        for(auto& k : mp){
            if(k.second>1){
                return 0;
            }
        }
        return 1;
    }

    int minimumOperations(vector<int>& nums) {
        int ct=0;
        for(int i=0; i<nums.size(); i+=3){
            if(check(nums, i)){
                return ct;
            }
            ct++;
        }
        return ct;
    }
};