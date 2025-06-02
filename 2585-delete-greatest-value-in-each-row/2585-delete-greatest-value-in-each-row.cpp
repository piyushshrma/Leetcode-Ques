class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int ans=0;
        int m=grid.size();
        int n=grid[0].size();
        
        for(int i=0; i<m; i++){
            sort(grid[i].begin(), grid[i].end());
        }
        
        for(int i=0; i<n; i++){
            int maxi=0;
            for(int j=0; j<m; j++){
                maxi = max(grid[j][i], maxi);
            }
            ans+=maxi;
        }
        return ans;
    }
};