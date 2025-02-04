class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int idx = 0; // To store the position in the modified array
        
        for (int i = 0; i < n;) {  // We use i++ within the while loop, so no need for i-- later
            char ch = chars[i];
            int count = 0;
            
            // Count occurrences of the current character
            while (i < n && chars[i] == ch) {
                count++;
                i++;
            }
            
            // Store the character at the current position
            chars[idx++] = ch;
            
            // If count > 1, we need to store the count digits as well
            if (count > 1) {
                string str = to_string(count);
                for (char dig : str) {
                    chars[idx++] = dig;  // Move idx forward for each digit
                }
            }
        }
        
        // Resize the vector to the final length
        chars.resize(idx);
        
        return idx;
    }
};
