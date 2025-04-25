class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n=nums.size();
        set<int> st(nums.begin(), nums.end());
        int res=0;
        int count=st.size();
        for(int i=0; i<n; i++){
            set<int> naya;
            for(int j=i; j<n; j++){
                naya.insert(nums[j]);
                if(naya.size()==count) res++;
            }
        }
    return res;
    }
};