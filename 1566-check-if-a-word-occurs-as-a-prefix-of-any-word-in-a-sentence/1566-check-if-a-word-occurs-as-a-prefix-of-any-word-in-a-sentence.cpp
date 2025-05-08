class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream ss(sentence);
        string word;

        for(int i = 0; ss >> word; i++){
            if(word.find(searchWord) == 0) 
                return i+1;
        }

        return -1;
    }
};