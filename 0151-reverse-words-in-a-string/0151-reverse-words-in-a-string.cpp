class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int n=s.size();
        string res="";
        for(int i=0; i<n; i++){
            string temp="";
            while(i<n && s[i]!=' '){
                temp+=s[i];
                i++;
            }
            reverse(temp.begin(), temp.end());
            if(temp.size()>=1){if(res.empty()){
            res+=temp;
            }

            else{
            res+= " " + temp;
            }}
        }

        return res;
    }
};