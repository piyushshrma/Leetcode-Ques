class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int row=dimensions.size();
        int col=dimensions[0].size();
        int maxArea=0;
        int maxDig=0;
        for(int i=0; i<row; i++){
            int len=dimensions[i][0];
            int bre=dimensions[i][1];
            int diag=len*len+bre*bre;
            if(diag>maxDig){
                maxDig=diag;
                maxArea=len*bre;
            }
            else if(diag==maxDig){
                maxArea=max(maxArea, len*bre);
            }
            
        }
        return maxArea;
    }
};