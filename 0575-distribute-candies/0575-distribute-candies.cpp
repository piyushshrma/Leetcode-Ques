class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        map<int, int> mp;
        for(auto& i: candyType){
            mp[i]++;
        }
        int n=candyType.size();

        if(mp.size()>=n/2) return n/2;
        return mp.size();
    }
};