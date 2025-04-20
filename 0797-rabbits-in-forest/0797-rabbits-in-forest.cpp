class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int, int> mp;

        for(auto& i : answers){
            mp[i]++;
        }

        int ans=0;

        for(auto& i : mp){
            int x = i.first; // answer
            int count=i.second; // kitne logo ne `x` ans diya
            int groupSize = x+1;

            int group = ceil((double)count/groupSize);

            ans+=groupSize*group;

        }

        return ans;
    }
};