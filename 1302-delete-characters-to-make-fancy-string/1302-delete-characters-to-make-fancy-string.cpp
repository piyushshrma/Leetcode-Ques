class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        int ct=1;
        ans+=s[0];
        for(int i=1; i<s.size(); i++){
            if(s[i-1]==s[i]){
                ct++;
            }
            else{
                ct=1;
            }
            if(ct<=2){
                ans+=s[i];
            }
        }
        return ans;
    }
};