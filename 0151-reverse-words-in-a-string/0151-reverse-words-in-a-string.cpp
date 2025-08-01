class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        string ans="";
        string temp="";

        for(int i=n-1; i>=0; i--){
            if(s[i]!=' '){
                temp+=s[i];
            }
            else if(!temp.empty()){
                reverse(temp.begin(), temp.end());
                ans+=temp;
                ans+=" ";
                temp="";
            }
        }

        if(!temp.empty()){
            reverse(temp.begin(), temp.end());
            ans+=temp;
            temp="";
        }
        if(ans[ans.size()-1]==' '){
            ans.pop_back();
        }
        return ans;
    }
};