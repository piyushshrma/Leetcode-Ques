class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int, int> mp;
        
        for (int i = 0; i < items1.size(); i++) {
        int value = items1[i][0];
        int weight = items1[i][1];
        mp[value] = weight;  // Map value to weight
        }

        for (int i = 0; i < items2.size(); i++) {
        int value = items2[i][0];
        int weight = items2[i][1];
        mp[value] += weight;  // Map value to weight
        }

        vector<vector<int>> ans;
        for(auto& i : mp){
            ans.push_back({i.first, i.second});
        }

        return ans;
    }
};