/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *removeLeafNodes(TreeNode *root, int target)
    {
        if (!root)
            return root;
        if (root->left)
            root->left = removeLeafNodes(root->left, target);
        if (root->right)
            root->right = removeLeafNodes(root->right, target);

        if (target == root->val && !root->left && !root->right)
            return NULL;
        return root;
    }
};
