class Solution {
public:
    int maxFreqSum(string s) {
        map<char, int> mp;
        for(auto& i : s){
            mp[i]++;
        }

        int maxV=0;
        int maxC=0;

        for(auto& i : mp){
            if(i.first=='a' || i.first=='e' || i.first=='i' || i.first=='o' || i.first=='u'){
                maxV=max(maxV,i.second);
            }
            else{
                maxC=max(maxC,i.second);
            }
        }
        return maxV+maxC;
    }
};