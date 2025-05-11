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
    vector<long long> levelOrder(TreeNode *root)
{
    vector<long long> sumByLevel;
    if (root == NULL)
        return sumByLevel;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int levelSize = q.size(); // Number of nodes at current level
        long long levelSum = 0;         // Sum of node values at current level

        for (int i = 0; i < levelSize; ++i)
        {
            TreeNode *curr = q.front();
            q.pop();

            levelSum += curr->val;

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }

        sumByLevel.push_back(levelSum);
    }
    return sumByLevel;
}

    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> ans= levelOrder(root);
        sort(ans.begin(), ans.end(), greater<long long>());
        // long long finalAns = ;
        if (k>ans.size()){
            return -1;
        }
        return ans[k-1];
    }
};