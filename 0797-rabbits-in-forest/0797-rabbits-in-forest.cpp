class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int, int> mp;

        for(auto& i : answers){
            mp[i]++;
        }

        int ans=0;

        for(auto& i : mp){
            int x = i.second;  // Number of rabbits giving the same answer
            int groupSize = i.first + 1;  // Group size for this answer

            // The number of groups needed to fit these rabbits
            // (rounding up the division)
            int numGroups = (x + groupSize - 1) / groupSize;

            // Add the total number of rabbits to the answer
            ans += numGroups * groupSize;
        }

        return ans;
    }
};