class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        vector<int> ans=prices;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(j>i && prices[j]<=prices[i]){
                    ans[i]=prices[i]-prices[j];
                    break;
                }
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> finalPrices(vector<int>& prices) {
//         int n=prices.size();
//         vector<int> ans=prices;
//         for(int i=0; i<n; i++){
//             for(int j=i+1; j<n; j++){
//                 if(j>i && prices[j]<=prices[i]){
//                     ans[i]=prices[i]-prices[j];
//                     break;
//                 }
//             }
//         }
//         return ans;
//     }
// };