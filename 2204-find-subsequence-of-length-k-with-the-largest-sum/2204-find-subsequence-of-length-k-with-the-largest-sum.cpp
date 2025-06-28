class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> numsIdx;
        for(int i=0; i<nums.size(); i++){
            numsIdx.push_back({nums[i], i});
        }

        //sort desc
        sort(numsIdx.begin(), numsIdx.end(), [](const pair<int, int>& a, const pair<int, int>& b){
            return a.first > b.first;
        });

        //take k values
        vector<pair<int, int>> topK(numsIdx.begin(), numsIdx.begin()+k);
        sort(topK.begin(), topK.end(), [](const pair<int, int>& a, const pair<int, int>& b){
            return a.second < b.second;
        });

        // get values
        vector<int> ans;
        for(auto& i : topK){
            ans.push_back(i.first);
        }

        return ans;
    }
};