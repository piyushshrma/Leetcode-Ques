class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.size();
        int countOfW=INT_MAX;
        for(int i=0; i<n; i++){
            if(i+k<=n){
                int W=0;
                for(int j=i; j < i+k; j++){
                    if(blocks[j]=='W'){
                        W++;
                    }
                }
                countOfW = min(countOfW, W);
            }
        }
        return countOfW;
    }
};