class Solution {
 public:
  int punishmentNumber(int n) {
    int ans = 0;
    
    // Loop through all integers i from 1 to n
    for (int i = 1; i <= n; ++i) {
      // Check if the square of i can be split to sum to i
      if (isPossible(0, 0, to_string(i * i), 0, i))
        ans += i * i;  // If it is, add i^2 to the total sum
    }
    
    return ans;  // Return the total sum
  }

 private:
  // Recursive function to check if the sum of any split of `numChars` equals the target (i)
  bool isPossible(int accumulate, int running, const string& numChars, int s, int target) {
    if (s == numChars.length()) {
      // If we've reached the end of the string, check if the sum equals the target
      return target == accumulate + running;
    }

    const int d = numChars[s] - '0';  // Get the digit at position s
    // Recursively try two options:
    // 1. Add the current digit to the running number (build the number)
    // 2. Add the running number to the accumulate sum, and start a new number with the current digit
    return isPossible(accumulate, running * 10 + d, numChars, s + 1, target) || 
           isPossible(accumulate + running, d, numChars, s + 1, target);
  }
};
