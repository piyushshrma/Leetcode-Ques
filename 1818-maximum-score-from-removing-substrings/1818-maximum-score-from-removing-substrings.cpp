class Solution {
public:
    string removePairs(string& s, char first, char second, int score, int& total){
        stack<char> st;
        for(char c : s){
            if(!st.empty() && st.top() == first && c == second){
                st.pop();
                total+=score;
            }
            else{
                st.push(c);
            }
        }

        // Rebuild the string
        string res;
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
    int maximumGain(string s, int x, int y) {
        int total = 0;
        if(x>y){
            s = removePairs(s, 'a', 'b', x, total);
            s = removePairs(s, 'b', 'a', y, total);
        }
        else{
            s = removePairs(s, 'b', 'a', y, total);
            s = removePairs(s, 'a', 'b', x, total);
        }
        return total;
    }
};