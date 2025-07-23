class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> ct(n+2,0);
        for(int i=0; i<edges.size(); i++){
            int a=edges[i][0];
            int b=edges[i][1];

            ct[a]++;
            ct[b]++;
        }
        int maxi=INT_MIN;
        for(int i=1; i<=n+1; i++){
            if(ct[i]==n){
                return i;
            }
        }
        return -1;
    }
};