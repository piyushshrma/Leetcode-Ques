class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0;
        int left = 0;
        unordered_map<char, int> char_count;
        
        // Loop through the string with the right pointer
        for (int right = 0; right < s.length(); ++right) {
            char_count[s[right]]++;  // Add the character to the window
            
            // Shrink the window until it contains at least one 'a', 'b', and 'c'
            while (char_count['a'] > 0 && char_count['b'] > 0 && char_count['c'] > 0) {
                count += s.length() - right;  // Add the valid substrings
                char_count[s[left]]--;  // Shrink the window from the left
                left++;
            }
        }
        
        return count;
    }
};
