class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int n=s.size();
        int numOfGrp=n/k;

        string choti="";
        int ct=0;
        for(int i=0; i<n; i++){
            choti+=s[i];
            ct++;
            if(ct==k){
                ct=0;
                ans.push_back(choti);
                choti="";
            }
        }
        

        if(n%k!=0){string nayi="";
        int nahiGaya=n%k;
        for(int i=n-nahiGaya; i<n; i++){
            nayi+=s[i];
        }
        int nayiKiSize=nayi.size();
        for(int i=0; i<k - nayiKiSize; i++){
            nayi+=fill;
        }
        ans.push_back(nayi);}

        return ans;
    }
};