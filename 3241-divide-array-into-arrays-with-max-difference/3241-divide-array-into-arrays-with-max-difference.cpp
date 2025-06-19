class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> finAns;
        
        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size(); i+=3){
            if(i+2>=nums.size() || (nums[i+2]-nums[i]>k)) return {};
            finAns.push_back({nums[i],nums[i+1],nums[i+2]});    
        }
        return finAns;
    }
};