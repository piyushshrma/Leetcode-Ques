class Solution {
public:
    string helper(string s, int k){
        string news=s;
        while(news.length()<k){
            string add="";
            int n=news.length();
            for(int i=0; i<n; i++){
                add+=news[i]+1;
            }
            news=news+add;
        }
        return news;
    }
    char kthCharacter(int k) {
        string ini = "a";
        string ans = helper(ini, k);
        return ans[k-1];
    }
};