class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen=0;
        int n=s.length();
        if(n<=0){
            return 0;
        }
        for(int i=0; i<n; i++){
            vector<int> freq(128,0);
            int curr=0;
            for(int j=i; j<n; j++){
                
                if(freq[s[j]]==0){
                    curr++;
                    freq[s[j]]++;
                    maxLen=max(maxLen, curr);
                }
                else{
                    break;
                }
            }
        }
        return maxLen;
    }
};