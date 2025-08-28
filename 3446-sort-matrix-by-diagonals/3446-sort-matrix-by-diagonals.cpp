class Solution {
public:
    void sortDiag(int row, int col, vector<vector<int>>& grid, bool asc){
        int i=row, j=col;
        vector<int> vec;
        while(i<grid.size() && j<grid.size()){
            vec.push_back(grid[i][j]);
            i++; j++;
        }
        if(asc){
            sort(vec.begin(), vec.end());
        }
        else{
            sort(vec.begin(), vec.end(), greater<int>());
        }

        i=row, j=col;
        for(auto& val : vec){
            grid[i][j]=val;
            i++; j++;
        }
    }

    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        
        //bottom left
        for(int row=0; row<grid.size(); row++){
            sortDiag(row,0,grid,false);
        }

        //upper
        for(int col=1; col<grid[0].size(); col++){
            sortDiag(0, col, grid,true);
        }

        return grid;
    }
};