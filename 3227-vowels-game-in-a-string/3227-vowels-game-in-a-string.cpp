class Solution {
public:
    bool isVowel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
            return true;
        }
        return false;
    }
    bool doesAliceWin(string s) {
        int ctVow=0;
        for(int i=0; i<s.size(); i++){
            if(isVowel(s[i])){
                ctVow++;
            }
        }
        if(ctVow<=0){
            return false;
        }
        if(ctVow%2!=0){
            return true;
        }

        return true;
    }
};