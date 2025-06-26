class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        map<int, int> mp;
        for(auto& i : nums){
            mp[i]++;
        }
        vector<int> arr;
        for(auto& i : mp){
            if(i.second>=2) arr.push_back(i.first);
        }
        return arr;
    }
};