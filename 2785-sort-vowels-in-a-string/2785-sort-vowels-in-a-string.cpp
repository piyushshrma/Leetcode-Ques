class Solution {
public:

    bool isVowel(char c) {
        // Check if the character is a vowel (both uppercase and lowercase)
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || 
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    string sortVowels(string s) {
        string vowelInS="";
        for(int i=0; i<s.length(); i++){
            if(isVowel(s[i])){
                vowelInS+=s[i];
            }
        }
    //     int n=vowelInS.size();
    //     for (int i = 0; i < n - 1; i++) {
    //     for (int j = 0; j < n - 1 - i; j++) {
    //         // If the ASCII value of the current character is greater than the next character
    //         if (vowelInS[j] > vowelInS[j + 1]) {
    //             // Swap the characters
    //             swap(vowelInS[j], vowelInS[j + 1]);
    //         }
    //     }
    // }
    sort(vowelInS.begin(), vowelInS.end());

        string ans="";
        int idx=0;
        for(int i=0; i<s.length(); i++){
            if(isVowel(s[i])){
                ans+=vowelInS[idx++];
            }
            else ans+=s[i];
        }
        return ans;
    }
};