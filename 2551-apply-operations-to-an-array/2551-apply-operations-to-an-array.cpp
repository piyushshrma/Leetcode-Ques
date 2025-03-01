class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
        for(int i=1; i<n; i++){
            if(nums[i-1]==nums[i]){
                nums[i-1]=nums[i]*2;
                nums[i]=0;
            }
            if(nums[i]==0){
                continue;
            }
            else{
                continue;
            }
        }
        vector<int> arr=nums;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(arr[i]==0 && arr[j]!=0){
                    swap(arr[j],arr[i]);
                }
            }
        }

        return arr;
    }
};