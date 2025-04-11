class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        vector<int> ans;
        

        for(int i=low; i<=high; i++){
            string s;
            s=to_string(i);
            int n=s.size();
            if(n%2!=0) continue;
            int first=n/2;
            int lside=0, rside=0;
            for(int j=0; j<first; j++){
                lside+=s[j]-'0';
            }
            for(int j=first; j<n; j++){
                rside+=s[j]-'0';
            }

            if(lside==rside){
                ans.push_back(i);
            }
        }
        return ans.size();
    }
};