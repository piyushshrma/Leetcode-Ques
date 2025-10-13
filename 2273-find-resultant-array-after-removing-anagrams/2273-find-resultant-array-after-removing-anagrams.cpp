class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        for(int i=1; i<words.size(); i++){
            map<char, int> a;
            map<char, int> b;
            for(auto& i : words[i-1]){
                a[i]++;
            }
            for(auto& i : words[i]){
                b[i]++;
            }
            if(a==b){
                words.erase(words.begin()+i);
                i--;
            }
        }
        return words;
    }
};