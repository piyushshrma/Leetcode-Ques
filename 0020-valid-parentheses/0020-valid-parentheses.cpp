class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        int n=s.length();
        if(n<=1) return 0;
        // st.push(s[0]);
        for(int i=0; i<n; i++){
            if(!st.empty() && ((s[i]==')' && st.top()=='(') || (s[i]=='}' && st.top()=='{') || (s[i]==']' && st.top()=='['))){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
            
        }
        return st.size()==0;
    }
};

// class Solution {
// public:
//     bool isValid(string s) {
//     vector<int> count(6,0);
//     for(int i=0; i<s.length(); i++){
//         if(s[i]=='('){
//             count[0]++;
//         }
//         else if(s[i]==')'){
//             count[1]++;
//         }
//         else if(s[i]=='{'){
//             count[2]++;
//         }
//         else if(s[i]=='}'){
//             count[3]++;
//         }
//         else if(s[i]=='['){
//             count[4]++;
//         }
//         else if(s[i]==']'){
//             count[5]++;
//         }
//     }
//     if(count[0]!=count[1] || count[2]!=count[3] || count[4]!=count[5]){
//         return 0;
//     }
//     return 1;
//     }
// };