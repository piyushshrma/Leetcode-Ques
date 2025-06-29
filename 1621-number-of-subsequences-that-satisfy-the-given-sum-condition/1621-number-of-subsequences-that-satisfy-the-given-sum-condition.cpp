class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int mod = 1e9 + 7;
        int n = nums.size();
        int sum=0;
        sort(nums.begin(), nums.end());
        vector<int> power(n,1);
        for(int i=1; i<n; i++){
            power[i]=(power[i-1]*2) % mod;
        }

        int low=0, high=n-1;

        while(low<=high){
            // int mid = low + (high - low) / 2;
            if(nums[low]+nums[high]<=target){
                sum=(sum+power[high-low]) % mod;
                low++;
            }
            else{
                high--;
            }
        }
        return sum;
    }
};