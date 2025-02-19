class Solution {
public:
    // Vector to store the valid "happy strings".
    std::vector<std::string> happyStrings;

    // Main function to return the k-th happy string of length n.
    // If there aren't k happy strings, an empty string is returned.
    std::string getHappyString(int length, int k) {
        // Initiate a depth-first search to generate all happy strings of length 'n'
        generateHappyStrings("", length);
        // Check if there are less than 'k' happy strings, return "" if true.
        // Otherwise, return the k-th string (0-indexed, so we use k-1).
        return happyStrings.size() < k ? "" : happyStrings[k - 1];
    }

private:
    // Helper function to generate happy strings using DFS.
    void generateHappyStrings(std::string current, int length) {
        // If the current string has reached the target length 'n',
        // add it to the list of happy strings and return.
        if (current.size() == length) {
            happyStrings.push_back(current);
            return;
        }
        // Iterate over each character from 'a' to 'c'.
        for (char nextChar = 'a'; nextChar <= 'c'; ++nextChar) {
            // If the last character is the same as the next character,
            // skip to maintain the "happy" property.
            if (!current.empty() && current.back() == nextChar) continue;
            // Append the new character and continue the search.
            current.push_back(nextChar);
            generateHappyStrings(current, length);
            // Backtrack by removing the last character added.
            current.pop_back();
        }
    }
};