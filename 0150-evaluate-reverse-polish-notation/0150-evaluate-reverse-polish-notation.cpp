class Solution {
public:
    int evalRPN(vector<string>& s) {
        int ans=0;
        stack<int> st;
        for(int i=0; i<s.size(); i++){
            if((s[i] == "+" || s[i] == "/" || s[i] == "*" || s[i] == "-")){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                if(s[i]=="+"){
                    st.push(a+b);
                }
                if(s[i]=="-"){
                    st.push(b-a);
                }
                if(s[i]=="*"){
                    st.push(a*b);
                }
                if(s[i]=="/"){
                    st.push(b/a);
                }
            }else {
                st.push(stoi(s[i]));  // only push if it’s a number
            }
        }
        return st.top();
    }
};