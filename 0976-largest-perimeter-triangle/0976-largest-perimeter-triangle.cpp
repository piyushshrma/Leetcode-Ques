class Solution {
public:
    bool isPossible(int a, int b, int c){
        if(a + b > c && a + c > b && b + c > a){
            return true;
        }
        return false;
    }
    int largestPerimeter(vector<int>& nums) {
        if(nums.size()<3){
            return 0;
        }
        sort(nums.begin(), nums.end(), greater<int>());
        int currPeri=0;
        int maxPeri=0;
        for(int i=0; i<nums.size()-2; i++){
            int a=nums[i],b=nums[i+1],c=nums[i+2];
                    if(isPossible(a,b,c)){
                        currPeri=a+b+c;
                        maxPeri=max(maxPeri, currPeri);
                    }
        }    
        return maxPeri;    
    }
};