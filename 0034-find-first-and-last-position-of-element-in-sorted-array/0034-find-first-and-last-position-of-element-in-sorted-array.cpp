class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans = {-1,-1};
        if(n<=0){
            return {-1, -1};
        }
        int left=0;
        int right=n-1;

        while(left<=right){
            int mid=left+(right-left)/2;
            
            if(nums[mid]>target){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
            
            if(nums[mid]==target){
                int pahla=mid,dusra=mid;
                while(pahla>=0 && nums[pahla]==target){
                    pahla--;
                }
                while(dusra<=nums.size()-1 && nums[dusra]==target){
                    dusra++;
                }
                ans[0]=pahla+1;
                ans[1]=dusra-1;
            }
        }
        return ans;
    }
};