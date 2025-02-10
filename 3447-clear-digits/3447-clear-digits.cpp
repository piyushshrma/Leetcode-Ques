class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++) {
            if((s[i] >= 'a' && s[i] <= 'z')) {
                st.push(s[i]);
            }
            else if(s[i] >= '0' && s[i] <= '9') {
                st.pop();
            }
        }
        
        string ns;
        while (!st.empty()) {
            char top = st.top();  // Get the top element
            ns += top;            // Append the top element
            st.pop();             // Pop the top element
        }
        
        reverse(ns.begin(), ns.end());

        return ns;
    }
};
