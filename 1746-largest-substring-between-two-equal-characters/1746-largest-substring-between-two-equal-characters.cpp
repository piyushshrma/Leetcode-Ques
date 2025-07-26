class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int maxSize=-1;
        for(int i=0; i<s.size(); i++){
            for(int j=s.size()-1; j>=0; j--){
                if(s[i]==s[j]){
                    maxSize=max(maxSize, j-i-1);
                }
            }
        }
        // if(maxSize==0){
        //     return -1;
        // }
        return maxSize;
    }
};