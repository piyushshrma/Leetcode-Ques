class Solution {
public:

    int get(vector<int>& nums){
        int x=0;
        for(int i=0; i<nums.size(); i++){
            x^=nums[i];
        }
        return x;
    }

    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int t=0;
        if(nums1.size()%2==1){
            t^=get(nums2);
        }

        if(nums2.size()%2==1){
            t^=get(nums1);
        }
        return t;
    }
};