class Solution {
public:
    bool isPalindrome(string str) {
        if(str[0]==0 || str[0]==1 || str[0]==2 || str[0]==3 || str[0]==4 || str[0]==5 || str[0]==6 || str[0]==7 || str[0]==8 || str[0]==9){
            return false;
        }
        for (int i = 0; i < str.length(); ++i) {
            if(isalpha(str[i]) || isdigit(str[i])){
            str[i] = tolower(str[i]);}
            else{
                str.erase(i,1);
                --i;
            }
        }
        string c;
        for(int i=str.length()-1; i>=0; i--){
            c+=str[i];
        }
        if(c==str){
            return true;
        }
        else{return false;}
}
};