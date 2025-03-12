class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        int neg=0;
        int ct=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<0){
                neg++;
            }
            else if(nums[i]==0){
                ct++;
            }
        }
        return max(neg,abs(n-neg-ct));
    }
};