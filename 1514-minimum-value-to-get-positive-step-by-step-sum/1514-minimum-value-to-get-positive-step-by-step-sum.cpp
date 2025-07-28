class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum=0;
        int minPrefSum=0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            minPrefSum=min(minPrefSum, sum);
        }
        if(minPrefSum<0)
            return 1-minPrefSum;
        return 1;
    }
};