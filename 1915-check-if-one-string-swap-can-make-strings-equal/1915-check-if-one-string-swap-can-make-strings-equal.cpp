class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2) return true;
        int freq1[26]={0};
        int freq2[26]={0};
        int n=s1.length();
        for(int i=0; i<n; i++){
            freq1[s1[i]-'a']++;
            freq2[s2[i]-'a']++;
        }
        for(int i=0; i<26; i++){
            if(freq1[i]!=freq2[i]){
                return false;
            }
        }

        int ct=0;
        int st=0;
        int end=s1.length()-1;
        while(st<=end){
            if(s1[st]!=s2[st]) ct++;
            st++;
        }
        if(ct==2) return true;
        return false;
    }
};