class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxC=0;
        int n=s.size();
        for(int i=0; i<n; i++){
            vector<int> freq(128,0);
            int curr=0;
            for(int j=i; j<n; j++){
                if(freq[s[j]]==0){
                    curr++;
                    freq[s[j]]++;
                    maxC=max(maxC, curr);
                }
                else{
                    break;
                }
            }
        }
        return maxC;
    }
};