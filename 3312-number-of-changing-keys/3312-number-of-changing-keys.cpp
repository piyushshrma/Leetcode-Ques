class Solution {
public:
    int countKeyChanges(string s) {
        int ans=0;
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        for(int i=1; i<s.length(); i++){
            if(s[i-1]!=s[i]) ans++;
        }
        return ans;
    }
};