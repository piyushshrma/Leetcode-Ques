class Solution {
public:

    bool even(int num){
        string s=to_string(num);
        return s.size()%2==0;
    }
    int findNumbers(vector<int>& nums) {
        int count=0;
        for(int i=0; i<nums.size(); i++){
            if(even(nums[i])){count++;}
        }
        return count;
    }
};