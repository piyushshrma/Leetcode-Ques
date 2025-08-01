class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        ans.push_back({1});
        if(n>1){
            ans.push_back({1,1});
        }
        // n=n-2;
        for(int i=2; i<n; i++){
            vector<int> oned;
            oned.push_back(1);
            for(int j=1; j<i; j++){
                int val=ans[i-1][j]+ans[i-1][j-1];
                oned.push_back(val);
            }
            oned.push_back(1);
            ans.push_back(oned);
        }
        return ans;
    }
};