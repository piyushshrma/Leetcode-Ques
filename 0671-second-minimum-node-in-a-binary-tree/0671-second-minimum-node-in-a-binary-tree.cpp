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

        void printInorder(TreeNode *root, set<int>& ino)
{
    if (root == NULL)
    {
        return;
    }
    printInorder(root->left, ino);  // Traverse left subtree
    ino.insert(root->val); // Print current node
    printInorder(root->right, ino); // Traverse right subtree
}

    int findSecondMinimumValue(TreeNode* root) {
        set<int> ans;
        printInorder(root, ans);
        if(ans.size()<2){
            return -1;
        }
        else{
            auto it = ans.begin();

            // Advance the iterator to the 2nd index (3rd element in 0-based index)
            advance(it, 1);
            return *it;
        }
        return -1;
    }
};