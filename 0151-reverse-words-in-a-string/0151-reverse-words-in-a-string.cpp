class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        string temp="";

        for(int i=s.size()-1; i>=0; i--){
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
                ans+=" ";
                temp="";
        }

        if(ans[ans.size()-1]==' '){
            ans.pop_back();
        }

        return ans;
    }
};