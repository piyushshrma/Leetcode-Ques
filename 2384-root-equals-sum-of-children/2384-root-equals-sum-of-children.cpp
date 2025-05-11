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

    void findLeaves(TreeNode* root, vector<int>& leaves) {
    if (!root) return;
    if (!root->left && !root->right) {
        // It's a leaf node
        leaves.push_back(root->val);
    } else {
        findLeaves(root->left, leaves);
        findLeaves(root->right, leaves);
    }
}

    bool checkTree(TreeNode* root) {
        if (!root) return false;
        int totSum=0;
        vector<int> leaves;
        int value=root->val;

        findLeaves(root, leaves);
        
        for(int i=0; i<leaves.size(); i++){
            totSum += leaves[i];
        }
        
        return value==totSum;
    }
};