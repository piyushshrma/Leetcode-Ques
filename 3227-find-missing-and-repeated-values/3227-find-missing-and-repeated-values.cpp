// class Solution {
// public:
//     vector<int> findMissingAndRepeatedValues(vector<vector<int>>& vec) {
//         int n = vec.size();
//         vector<int> count(n * n + 1, 0); // Initialize count array

//         for (const auto& innervec : vec) {
//             for (int element : innervec) {
//                 count[element]++;
//             }
//         }

//         vector<int> ans;
//         int repeated = -1;
//         int missing = -1;

//         for (int i = 1; i <= n * n; ++i) {
//             if (count[i] == 2) {
//                 repeated = i;
//             } else if (count[i] == 0) {
//                 missing = i;
//             }
//         }

//         ans.push_back(repeated);
//         ans.push_back(missing);
//         return ans;
//     }
// };

// Optimized Approach
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;
        unordered_set<int> s;
        int n = grid.size();
        int a,b;
        int expSum=0,actualSum=0;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                actualSum+=grid[i][j];
                if(s.find(grid[i][j])!=s.end()){
                    a=grid[i][j];
                    ans.push_back(a);
                }
                s.insert(grid[i][j]);
            }
        }
        expSum=(n*n)*(n*n+1)/2;
        b=expSum+a-actualSum;
        ans.push_back(b);

        return ans;
    }
};
