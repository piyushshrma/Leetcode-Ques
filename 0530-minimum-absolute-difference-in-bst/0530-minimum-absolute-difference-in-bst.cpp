/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Function to collect all the values from the tree
    void collectValues(TreeNode* root, vector<int>& values) {
        if (root == NULL) {
            return;
        }
        values.push_back(root->val);  // Add current node value
        collectValues(root->left, values);  // Traverse left subtree
        collectValues(root->right, values); // Traverse right subtree
    }

    int getMinimumDifference(TreeNode* root) {
        vector<int> values;
        collectValues(root, values);  // Collect all node values in the tree

        sort(values.begin(), values.end());  // Sort the values

        // Calculate the minimum difference between consecutive values in the sorted array
        // if (values.size() >= 2) {
            int minDiff = INT_MAX;
            for (int i = 1; i < values.size(); ++i) {
                minDiff = min(minDiff, values[i] - values[i - 1]);
            }
            return minDiff;
        // }
        return -1;  // Return -1 if there are fewer than 2 nodes
    }
};