class Solution {
public:
    int possibleStringCount(string word) {
        int ct=1;
        int n=word.size();
        for(int i=1; i<n; i++){
            if(word[i-1]==word[i]){
                ct++;
            }
        }
        return ct;
    }
};