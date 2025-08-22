class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        
        int row_min=INT_MAX,row_max=INT_MIN,col_min=INT_MAX,col_max=INT_MIN;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==1){
                    row_min=min(row_min, i);
                    row_max=max(row_max, i);
                    col_min=min(col_min, j);
                    col_max=max(col_max, j);
                }
            }
        }
        return (row_max-row_min+1)*(col_max-col_min+1);
    }
};