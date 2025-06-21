class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> mp;

        for(auto& i : word){
            mp[i]++;
        }

        vector<int> freq;
        for(auto& i : mp){
            freq.push_back(i.second);
        }
        sort(freq.begin(), freq.end());

        int minDel=INT_MAX;
        int n=freq.size();

        for(int i=0; i<n; i++){
            int base=freq[i];
            int totalDel=0;

            for(int j=0; j<i; j++){
                totalDel+=freq[j];
            }

            for(int j=i; j<n; j++){
                if(freq[j]>base+k){
                    totalDel+=freq[j]-(base+k);
                }
            }

            if(totalDel<minDel){
                minDel=totalDel;
            }
        }
        return minDel;
    }
};