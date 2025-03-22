class Solution {
public:
    int fib(int n) {
        int sum=0;
        if(n==0){
            return sum;
        }
        
        else if(n==1||n==2){
            sum++;
        }

        else{
            return fib(n-1)+fib(n-2);
        }
        
        return sum;
    }
};