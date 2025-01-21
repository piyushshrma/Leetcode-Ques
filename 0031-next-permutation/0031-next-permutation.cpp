class Solution {
public:
    void nextPermutation(vector<int>& A) {
        int n = A.size();
        int pivotIdx = -1;

        // Find the first decreasing element from the end
        for (int i = n - 2; i >= 0; i--) {
            if (A[i] < A[i + 1]) {
                pivotIdx = i;
                break;
            }
        }

        if (pivotIdx != -1) {
            // Find the smallest element greater than A[pivotIdx] to swap with
            for (int i = n - 1; i > pivotIdx; i--) {
                if (A[i] > A[pivotIdx]) {
                    swap(A[i], A[pivotIdx]);
                    break;
                }
            }
        }

        // Reverse the suffix to get the next smallest lexicographical order
        reverse(A.begin() + pivotIdx + 1, A.end());
    }
};
