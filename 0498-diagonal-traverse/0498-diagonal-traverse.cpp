class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map<int, vector<int>> mp;
        vector<int> res;
        int m=mat.size();
        int n=mat[0].size();

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }

        bool flip=true;
        for(auto& i : mp){
            if(flip){
                reverse(i.second.begin(), i.second.end());
            }

            for(int val : i.second){
                res.push_back(val);
            }

            flip = !flip;
        }
        return res;
    }
};