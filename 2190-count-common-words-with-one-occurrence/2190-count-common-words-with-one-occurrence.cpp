class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        map<string, int> mp1;
        map<string, int> mp2;
        for(auto& i : words1){
            mp1[i]++;
        }
        for(auto& i : words2){
            mp2[i]++;
        }
        vector<string> v1;
        vector<string> v2;
        for(auto& i : mp1){
            if(i.second==1){
                v1.push_back(i.first);
            }
        }

        for(auto& i : mp2){
            if(i.second==1){
                v2.push_back(i.first);
            }
        }
        int count=0;
        for(int i=0; i<v1.size(); i++){
            for(int j=0; j<v2.size(); j++){
                if(v1[i]==v2[j]){
                    count++;
                }
            }
        }
        return count;
    }
};