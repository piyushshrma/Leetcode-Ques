class Solution {
public:
    int hammingDistance(const string& a, const string& b) {
        int dist = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) ++dist;
        }
        return dist;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1);     // dp[i] = length of longest subsequence ending at i
        vector<int> prev(n, -1);  // prev[i] = previous index in the sequence

        int maxLen = 1, endIndex = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (groups[i] != groups[j] &&
                    words[i].length() == words[j].length() &&
                    hammingDistance(words[i], words[j]) == 1) {
                    
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                endIndex = i;
            }
        }

        // Reconstruct the longest valid subsequence
        vector<string> result;
        while (endIndex != -1) {
            result.push_back(words[endIndex]);
            endIndex = prev[endIndex];
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
