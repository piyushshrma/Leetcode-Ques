class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string, int> mp;
        for(auto& i : arr){
            mp[i]++;
        }
        vector<string> st;
        for(auto& i : arr){
            if(mp[i]==1){
                st.push_back(i);
            }
        }
        if (k <= st.size()) {
            return st[k - 1];  // As k is 1-based
        }
        return "";
    }
};