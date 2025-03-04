class Solution {
public:
    bool checkPowersOfThree(int n) {
        if (n <= 0) return false;  // Handle the case where n is non-positive

        while (n > 0) {
            if(n%3==2) return false;
            n = n / 3;  // Divide by 3 while it's divisible
        }

        return true;  // If n is 1, it's a power of 3
    }
};
