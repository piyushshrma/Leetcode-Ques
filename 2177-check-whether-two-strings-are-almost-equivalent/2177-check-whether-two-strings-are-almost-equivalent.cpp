class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        map<char,int> w1;
        map<char,int> w2;

        for(auto& i : word1){
            w1[i]++;
        }
        for(auto& i : word2){
            w2[i]++;
        }
        
        vector<int> freqOf1(26,0);
        for(auto& i : w1){
            int val=i.first-'a';
            freqOf1[val]=i.second;
        }

        vector<int> freqOf2(26,0);
        for(auto& i : w2){
            int val=i.first-'a';
            freqOf2[val]=i.second;
        }
        
        for(int i=0; i<26; i++){
            if(abs(freqOf1[i]-freqOf2[i])>3){
                return false;
            }
        }

        return true;
    }
};