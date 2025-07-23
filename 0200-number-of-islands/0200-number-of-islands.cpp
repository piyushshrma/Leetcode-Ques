class Solution {
public:
    void dfs(vector<vector<char>>& grid, int row, int col){
        if(row<0 || col<0 || row>=grid.size() || col>=grid[0].size() || grid[row][col] != '1'){
            return;
        }

        // Mark the current cell as visited
        grid[row][col]=2;

        dfs(grid, row-1, col);//up
        dfs(grid, row+1, col);//down
        dfs(grid, row, col-1);//left
        dfs(grid, row, col+1);//right
    }

    int numIslands(vector<vector<char>>& grid) {
        int islandCount=0;
        
        // Traverse each cell in the grid
        for(int row=0; row<grid.size(); row++){
            for(int col=0; col<grid[0].size(); col++){
                if(grid[row][col]=='1'){
                    islandCount++;
                    dfs(grid, row, col);
                }
            }
        }
        return islandCount;
    }
};