class Solution {
public:
    int maxDistance(string s, int k) {
        int north=0, south=0, east=0, west=0;
        
        int finAns = 0;
        
        for(int i=0; i<s.size(); i++){
            if(s[i]=='N'){
                north++;
            }
            if(s[i]=='S'){
                south++;
            }
            if(s[i]=='E'){
                east++;
            }
            if(s[i]=='W'){
                west++;
            }
            int x=abs(east-west);
            int y=abs(north-south);
            int MD=x+y;
            int inc=min(2*k, (i+1)-MD);
            finAns=max(finAns,MD+inc);
        }
        return finAns;
    }
};