class Solution {
public:
    int maxDifference(string s) {
        map<char, int> mp;

        for(auto& i : s){
            mp[i]++;
        }

        int maxOdd=INT_MIN, minEven=INT_MAX;

        for(auto& i : mp){
            if(i.second%2!=0){
                maxOdd=max(maxOdd, i.second);
            }
            if(i.second%2==0 && i.second>0){
                minEven=min(minEven,i.second);
            }
        }

        return maxOdd-minEven;
    }
};