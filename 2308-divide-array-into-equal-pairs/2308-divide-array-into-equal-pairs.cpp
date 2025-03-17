class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=1; i<nums.size(); i+=2){
                if(nums[i]==nums[i-1]){
                    count++;
            }
        }
        return (count>=n/2);
    }
};