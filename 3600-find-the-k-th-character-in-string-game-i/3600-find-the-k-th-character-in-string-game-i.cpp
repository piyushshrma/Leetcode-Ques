class Solution {
public:
    char kthCharacter(int k) {
        string s="a";
        while(s.length()<k){
            string temp="";
            for(int i=0; i<s.size(); i++){
                if(s[i]=='z'){
                    temp.push_back('a');
                }
                temp.push_back(s[i]+1);
            }
            s+=temp;
        }
        return s[k-1];
    }
};