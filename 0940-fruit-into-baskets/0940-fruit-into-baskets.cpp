class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int left=0;
        int right=0;
        map<int, int> mp;
        int ans=0;
        while(right<n){
            mp[fruits[right]]++;
            if(mp.size()<=2){
                ans=max(ans, right-left+1);
            }
            else{
                mp[fruits[left]]--;
                if(mp[fruits[left]]==0){
                    mp.erase(fruits[left]);
                }
                left++;
            }
            right++;
        }
        return ans;
    }
};

// class Solution {
// public:
//     int totalFruit(vector<int>& fruits) {
//         int maxCt=0;
//         for(int i=0; i<fruits.size(); i++){
//             set<int> st;
//             int ct=0;
//             int j=i;
//             while(j<fruits.size() && st.size()<=2){
//                 st.insert(fruits[j]);
//                 if(st.size()>=3){
//                     break;
//                 }
//                 ct++;
//                 j++;
//             }
//             maxCt=max(ct, maxCt);
//         }
//         return maxCt;
//     }
// };