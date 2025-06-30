class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size()==1){
            if(citations[0]==0){
                return 0;
            }
            return 1;
        }
        sort(citations.begin(), citations.end(), greater<int>());
        int ct=0;
        for(int i=0; i<citations.size(); i++){
            if(citations[i]>=i+1){
                ct=max(ct,i+1);
            }
        }
        return ct;
    }
};