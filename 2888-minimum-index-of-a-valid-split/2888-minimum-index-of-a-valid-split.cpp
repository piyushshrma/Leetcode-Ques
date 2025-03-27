class Solution {
public:
    // Moores Algorithm
    // for getting majority element
    int mooresAlgo(vector<int>& nums, int n){
        int majEle=nums[0];
        int freq=1;
        for(int i=1; i<n; i++){
            if(nums[i]==majEle){
                freq++;
            }
            else{
                freq--;
            }
            if(freq==0){
                majEle=nums[i];
                freq=1;
            }
        }
        return majEle;
    }

    int minimumIndex(vector<int>& nums) {
        int n=nums.size();
        int majEle = mooresAlgo(nums,n);

        int maxFreq=0;
        for(int i=0; i<n; i++){
            if(nums[i]==majEle){
                maxFreq++;
            }
        }

        int prefCount=0;
        for(int i=0; i<n-1; i++){
            if(nums[i]==majEle){
                prefCount++;
                maxFreq--;
            }
            if((prefCount>(i+1)/2) && (maxFreq>(n-i-1)/2)){
                return i;
            }
        }
        return -1;
    }
};