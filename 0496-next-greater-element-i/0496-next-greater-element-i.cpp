class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums2.size());
        stack<int> s;
        for(int i=nums2.size()-1; i>=0; i--){
            while(s.size()>0 && s.top()<=nums2[i]){
                s.pop();
            }
            if(s.empty()) ans[i]=-1;
            else ans[i]=s.top();
            s.push(nums2[i]);
        }
        vector<int> finans(nums1.size());
        for(int i=0; i<nums1.size(); i++){
            for(int j=0; j<nums2.size(); j++){
                if(nums1[i]==nums2[j]){
                    finans[i]=ans[j];
                }
            }
        }
        return finans;
    }
};