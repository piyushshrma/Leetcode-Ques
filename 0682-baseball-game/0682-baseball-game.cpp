class Solution {
public:
    int calPoints(vector<string>& arr) {
        stack<int> st;
        int n=arr.size();
        int i=0;
       for (int i = 0; i < n; ++i) {
            if(arr[i]=="C"){
                st.pop();
            }
            else if(arr[i]=="D"){
                int val=st.top()*2;
                st.push(val);
            }
            else if(arr[i]=="+"){
                int val1=st.top();
                st.pop();
                int val2=st.top();
                st.push(val1);
                st.push(val1+val2);
            }
            else{
                st.push(stoi(arr[i]));
            }
        }
        int newans=0;
    while(!st.empty()){
        newans+=(st.top());
        st.pop();
    }
    return newans;
    }
};



// Kaam aayega
    // // Access the top two values (without popping them)
    // int val1 = stk.top(); // val1 = 20
    // stk.pop();  // Remove the top value to access the second one
    // int val2 = stk.top(); // val2 = 10
    // stk.push(val1); // Push the first value back onto the stack