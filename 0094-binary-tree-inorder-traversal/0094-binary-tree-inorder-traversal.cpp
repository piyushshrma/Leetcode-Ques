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

    void printInorder(TreeNode *root, vector<int>& ino)
{
    if (root == NULL)
    {
        return;
    }
    printInorder(root->left, ino);  // Traverse left subtree
    ino.push_back(root->val); // Print current node
    printInorder(root->right, ino); // Traverse right subtree
}

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        printInorder(root,ans);
        return ans;
    }
};