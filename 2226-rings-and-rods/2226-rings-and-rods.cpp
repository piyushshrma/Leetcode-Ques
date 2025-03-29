class Solution {
public:
    int countPoints(string rings) {
        int n = rings.size();
        int newsize=n/2;
        vector<int> r(10,0);
        vector<int> g(10,0);
        vector<int> b(10,0);
        
        for(int i=0; i<n; i+=2){
            if(rings[i]=='R'){
                // int val=rings[i+1]-'0';
                int val = rings[i+1] - '0';

                r[val]++;
            }
            else if(rings[i]=='G'){
                // int val=rings[i+1]-'0';
                int val = rings[i+1] - '0';

                g[val]++;
            }
            else if(rings[i]=='B'){
                // int val=rings[i+1]-'0';
                int val = rings[i+1] - '0';

                b[val]++;
            }
        }

        int ans=0;
        for(int i=0; i<10; i++){
            if(r[i]>=1 && g[i]>=1 && b[i]>=1){
                ans++;
            }
        }
        return ans;

    }
};