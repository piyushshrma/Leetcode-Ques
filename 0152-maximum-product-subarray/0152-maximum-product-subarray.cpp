class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMul=1;
        int maxMul=INT_MIN;

        for(int i=0; i<nums.size(); i++){
            currMul*=nums[i];
            maxMul=max(currMul, maxMul);
            if(currMul==0){
                currMul=1;
            }
        }
        
        currMul = 1;

        // Right to left
        for (int i = nums.size() - 1; i >= 0; i--) {
            currMul *= nums[i];
            maxMul = max(maxMul, currMul);
            if (currMul == 0) currMul = 1;
        }

        return maxMul;
    }
};