class Solution {
  public:
    int mod = 1e9 + 7; // Large number to avoid overflow, typical in competitive programming

    // Recursive function to find the number of ways to decode starting from index i
    int rec(int i, string &str, vector<int> &dp) {
        // Agar hum string ke end par pahuch gaye hain, to ek valid decoding ho chuki hai
        if (i == str.length()) {
            return 1; // Empty string ka ek tareeke se decode ho sakta hai
        }
        
        // Agar dp[i] already calculated hai, to usko directly return kar do
        if (dp[i] != -1) {
            return dp[i]; // Already computed result use kar rahe hain
        }
        
        int choice1 = 0, choice2 = 0; // dono cases ke liye counts
        
        // Agar current character valid single digit hai (1-9 ke beech)
        if (str[i] >= '1' && str[i] <= '9') {
            // Recursively next index pe decoding count kar rahe hain
            choice1 = rec(i + 1, str, dp);
        }
        
        // 2 digits ka substring bana rahe hain
        string part = str.substr(i, 2);
        
        // Agar part valid two-digit number (10-26) ke beech hai, to usko consider karo
        if (part >= "10" && part <= "26" && i <= str.length() - 2) {
            // Recursively 2 indices aage ka decoding count kar rahe hain
            choice2 = rec(i + 2, str, dp);
        }
        
        // Dono choices ka result add karke dp[i] mein store karte hain
        dp[i] = (choice1 + choice2) % mod;
        return dp[i]; // Final result return karte hain
    }
    
    // Main function jo count karega decoding ke ways
    int countWays(string &str) {
        // dp array initialize kar rahe hain, sabko -1 se fill kar rahe hain (means not calculated)
        vector<int> dp(str.size(), -1);
        return rec(0, str, dp); // Starting from index 0 se recursive calculation kar rahe hain
    }
};
