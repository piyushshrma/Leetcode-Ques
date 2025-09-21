class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int low=nums[0],high=nums[nums.size()-1];
        int ans=1;
        for(int i=1; i<=low; i++){
            if(low%i==0 && high%i==0){
                ans=i;
            }
        }
        return ans;
    }
};