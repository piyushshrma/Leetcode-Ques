class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int> resSet;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]==key){
                // ans.push_back(i);
                for(int j=i-k; j<=i+k; j++){
                    if(j>=0 && j<=n-1) resSet.insert(j);
                }
            }
        }
        return vector<int>(resSet.begin(), resSet.end());
    }
};