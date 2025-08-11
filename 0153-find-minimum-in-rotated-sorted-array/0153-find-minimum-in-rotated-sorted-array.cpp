class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int high=n-1;
        if(n==1){
            return nums[0];
        }
        if(nums[0]<nums[n-1]){
            return nums[0];
        }
        while(left<=high){
            int mid=left+(high-left)/2;

            if(nums[mid]>nums[mid+1]){
                return nums[mid+1];
            }
            if(nums[mid]<nums[mid-1]){
                return nums[mid];
            }
            
            if (nums[mid] >= nums[0]) {
                left = mid + 1;
            } else {
                high = mid - 1; // Move left if mid is smaller than left
            }
        }
        return 0;
    }
};