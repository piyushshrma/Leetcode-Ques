class Solution {
public:

    int count1s(string s){
        int ans=0;

        for(int i=0; i<s.length(); i++){
            if(s[i]=='1'){
                ans++;
            }
        }

        return ans;
    }
    string intToStr(int n){
        string s;
    
        while (n > 0) {
        s = char((n % 2) + '0') + s;  // Convert remainder to char and prepend
        n /= 2;
        }

        return s;
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);
        if(n==0) return ans;

        for(int i=1; i<=n; i++){
            string s = intToStr(i);
            int noOf1s = count1s(s);
            ans.push_back(noOf1s);
        }

        return ans;
    }
};