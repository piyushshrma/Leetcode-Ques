class Solution {
public:

    long long calc_sum(long long mid){

        return mid*(mid+1)/2;
    }


    int arrangeCoins(int n) {
        int low=1, high=n;

        while(low<=high){
            int mid=low+(high-low)/2;
            long long sum = calc_sum(mid);

            if(n==sum) return mid;

            else if(n<sum){
                high=mid-1;
            }

            else{
                low=mid+1;
            }
        }
        return high;
    }
};