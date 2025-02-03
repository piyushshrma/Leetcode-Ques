class Solution {
public:

    bool isFreqSame(int freq1[], int freq2[]) {
        for(int i = 0; i < 26; i++) {
            if(freq1[i] != freq2[i]) {
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int freq[26] = {0};
        for (char c : s1) {
            freq[c - 'a']++;
        }

        int winSize = s1.length();
        int winFreq[26] = {0};

        for (int i = 0; i < s2.length(); i++) {
            // Add the current character to the window
            winFreq[s2[i] - 'a']++;

            // If the window size exceeds the size of s1, slide the window by removing the leftmost character
            if (i >= winSize) {
                winFreq[s2[i - winSize] - 'a']--;
            }

            // Check if the current window matches the frequency of s1
            if (i >= winSize - 1 && isFreqSame(freq, winFreq)) {
                return true;
            }
        }

        return false;
    }
};