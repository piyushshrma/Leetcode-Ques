class Solution {
public:
    const int MOD = 1e9 + 7;
    int lengthAfterTransformations(string s, int t) {
        int ans=0;
        // map<int, int> mp;
        vector<int> mp(26, 0);
        for(auto& i : s){
            mp[i-'a']++;
        }

        while(t--){
            // map<int, int> temp;
            vector<int> temp(26, 0);
            for(int it=0; it<26; it++){
                char ch=it+'a'; //0->a, 1->b
                int freq=mp[it];
                if(ch!='z'){
                    temp[(ch+1)-'a']=(temp[(ch+1)-'a']+freq)%MOD;
                }
                else{
                    temp['a'-'a']=(temp['a'-'a']+freq)%MOD;
                    temp['b'-'a']=(temp['b'-'a']+freq)%MOD;
                }
            }
            // mp=temp; below is same operation
            mp=move(temp);
        }

        for(int i=0; i<26; i++){
            ans=(ans+mp[i])%MOD;
        }
        return ans;
    }
};