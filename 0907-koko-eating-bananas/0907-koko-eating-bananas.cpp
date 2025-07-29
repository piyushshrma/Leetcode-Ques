class Solution {
public:
    bool isPossible(vector<int>& piles, int h, int mid){
        int hrsSum=0;
        int resAdd=0;

        for(int i=0; i<piles.size(); i++){
            int result = (piles[i] + mid - 1) / mid;
            hrsSum+=result;
            if(hrsSum>h){
                return false;
            }
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int st=1;
        int end=INT_MIN;
        for(int i=0; i<piles.size(); i++){
            end=max(end, piles[i]);
        }

        int ans=-1;

        while(st<=end){
            int mid=st+(end-st)/2;

            if(isPossible(piles, h, mid)){
                ans=mid;
                end=mid-1;
            }
            else{
                st=mid+1;
            }
        }
        return ans;
    }
};