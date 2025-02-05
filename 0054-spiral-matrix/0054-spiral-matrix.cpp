class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> ans;
        int maxele=n*m;

        int minr=0,minc=0,maxr=n-1,maxc=m-1;
        while(maxele>0){
                //top
                for(int r=minr, c=minc; c<=maxc && maxele>0; c++){
                    ans.push_back(matrix[r][c]);
                    maxele--;
                }
                minr++;
                //right
                for(int r=minr, c=maxc; r<=maxr && maxele>0; r++){
                    ans.push_back(matrix[r][c]);
                    maxele--;
                }
                maxc--;
                //bottom
                for(int r=maxr, c=maxc; c>=minc && maxele>0; c--){
                    ans.push_back(matrix[r][c]);
                    maxele--;
                }
                maxr--;
                //left
                for(int r=maxr, c=minc; r>=minr && maxele>0; r--){
                    ans.push_back(matrix[r][c]);
                    maxele--;
                }
                minc++;
        }
        return ans;
    }
};