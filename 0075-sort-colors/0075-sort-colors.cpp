class Solution {
public:
    void sortColors(vector<int>& nums) {
        int z=0,o=0,t=0;
        int n=nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                z++;
            }
            if(nums[i]==1){
                o++;
            }
            if(nums[i]==2){
                t++;
            }
        }
        if(z>=1){
        for(int i=0; i<o; i++){
            nums[i]=0;
        }}
        if(o>=1){
        for(int i=z; i<o+z; i++){
            nums[i]=1;
        }}
        if(t>=1){
        for(int i=o+z; i<o+z+t; i++){
            nums[i]=2;
        }}
    }
};