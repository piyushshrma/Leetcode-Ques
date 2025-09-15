class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        set<char> st(brokenLetters.begin(), brokenLetters.end());
        string curr="";
        vector<string> vecStr;

        for(int i=0; i<text.size(); i++){
            if(text[i]==' '){
                if(!curr.empty()){
                vecStr.push_back(curr);
                }
                curr="";
            }
            else{
                curr+=text[i];
            }
        }
        // Make sure to push the last word if there's one
        if (!curr.empty()) {
            vecStr.push_back(curr);
        }
        int ans=vecStr.size();
        for(int i=0; i<vecStr.size(); i++){
            for(int j=0; j<vecStr[i].size(); j++){
                if(st.find(vecStr[i][j])!=st.end()){
                    ans--;
                    break;
                }
            }
        }
        return ans;
    }
};