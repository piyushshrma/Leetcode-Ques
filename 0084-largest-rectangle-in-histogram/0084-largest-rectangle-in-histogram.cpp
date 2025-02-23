// class Solution {
// public:
//     int largestRectangleArea(vector<int>& arr) {
//         int size=arr.size();
//         int ans=0;
//         for(int i=0; i<size; i++){
//             int width=1,left=i,right=i;
//             int currArea;

//             while(left-1>=0 && arr[i]<=arr[left-1]){
//                 left--;
//                 width++;
//             }
//             while(right+1<size && arr[i]<=arr[right+1]){
//                 right++;
//                 width++;
//             }
//             // width=width-2;
//             currArea=arr[i]*width;
//             ans=max(ans,currArea);
//         }
//         return ans;
//     }
// };



class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        stack<int> s;
        int maxArea = 0;
        int n = arr.size();
        
        for (int i = 0; i <= n; i++) {
            // We process the current bar or an imaginary bar of height 0
            while (!s.empty() && (i == n || arr[s.top()] > arr[i])) {
                int height = arr[s.top()];
                s.pop();
                int width;
                if (s.empty()) {
                    width = i;
                } else {
                    width = i - s.top() - 1;
                }
                maxArea = max(maxArea, height * width);
            }
            s.push(i);
        }
        
        return maxArea;
    }
};
