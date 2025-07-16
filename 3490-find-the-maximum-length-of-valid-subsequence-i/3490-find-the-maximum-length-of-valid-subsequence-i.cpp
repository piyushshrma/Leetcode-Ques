class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int evenC=0, oddC=0;
        for(int num:nums){
            if(num%2==0){
                evenC++;
            }
            else{
                oddC++;
            }
        }
        int evenDp=0, oddDp=0;
        for(int num:nums){
            if(num%2==0){
                evenDp=max(evenDp, oddDp+1);
            }
            else{
                oddDp=max(oddDp, evenDp+1);
            }
        }
        return max({evenC, oddC, evenDp, oddDp});
    }
};