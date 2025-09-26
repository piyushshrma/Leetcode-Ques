class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int ct=0;
        int n=nums.size();
        for(int i=0; i<n-2; i++){
            for(int j=i+1; j<n-1; j++){
                for(int k=j+1; k<n; k++){
                    if (nums[i] + nums[j] > nums[k]) {
                        ct++;
                    } else {
                        // Since array is sorted, no further k will satisfy the condition
                        break;
                    }
                }
            }
        }
        return ct;
    }
};