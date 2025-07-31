class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        set<int> res, prev;

        for(int i=0; i<arr.size(); i++){
            set<int> curr;
            curr.insert(arr[i]);
            for(int num : prev){
                curr.insert(num|arr[i]);
            }
            for(int num : curr){
                res.insert(num);
            }
            prev=curr;
        }
        return res.size();
    }
};

// class Solution {
// public:
//     int subarrayBitwiseORs(vector<int>& arr) {
//         set<int> st;
//         for(int i=0; i<arr.size(); i++){
//             int currOR=0;
//             for(int j=i; j<arr.size(); j++){
//                 currOR = currOR | arr[j];
//                 st.insert(currOR);
//             }
//         }
//         return st.size();
//     }
// };