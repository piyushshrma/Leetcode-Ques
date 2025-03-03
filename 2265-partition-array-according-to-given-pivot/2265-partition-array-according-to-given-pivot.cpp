class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int> ans;
        vector<int> left;
        vector<int> right;
        int howmanypivot=0;
        for(int i=0; i<n; i++){
            if(nums[i]==pivot){
                howmanypivot++;
            }
        }
        for(int i=0; i<n; i++){
            if(nums[i]<pivot){
                left.push_back(nums[i]);
            }
            if(nums[i]>pivot){
                right.push_back(nums[i]);
            }
        }
        for(int i=0; i<left.size(); i++){
            ans.push_back(left[i]);
        }
        while(howmanypivot--){
            ans.push_back(pivot);
        }
        for(int i=0; i<right.size(); i++){
            ans.push_back(right[i]);
        }

        return ans;
    }
};