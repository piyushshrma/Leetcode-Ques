class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string, int> mp;
        vector<string> ans;
        int minSum = INT_MAX;

        for(int i=0; i<list1.size(); i++){
            mp[list1[i]]=i;
        }
        
        for(int j=0; j<list2.size(); j++){
            const string& word = list2[j];
            if(mp.find(word) == mp.end()){
                continue;
            }
            int sum = j + mp[word];
            if(sum<minSum){
                ans={word};
                minSum=sum;
            }
            else if(minSum==sum) ans.push_back(word);
        }
        return ans;
    }
};