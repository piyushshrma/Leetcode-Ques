class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string ans=countAndSay(n-1);
        //Processing
        string result="";
        for(int i=0; i<ans.length(); i++){
            char ch=ans[i];
            int ct=1;

            while(i<ans.length()-1 && ans[i]==ans[i+1]){
                ct++;
                i++;
            }

            result+=to_string(ct)+ch;
        }
        return result;
    }
};