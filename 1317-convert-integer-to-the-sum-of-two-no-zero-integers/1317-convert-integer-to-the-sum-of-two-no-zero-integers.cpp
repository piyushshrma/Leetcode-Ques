class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> ans;
        int A,B;
        for(int i=0; i<n; i++){
            A=i;
            B=n-i;
            if(A>=1 && B>=1){
                return {A,B};
            }
        }
        return {};
    }
};