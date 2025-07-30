class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxAns=INT_MIN;
        int left=0;
        int right=n-1;
        while(left<right){
            int mini=min(height[left], height[right]);
            int currAns=mini*(right-left);
            maxAns=max(currAns, maxAns);
            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxAns;
    }
};