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
    bool isSame(TreeNode *root, int val)
    {
        if (!root)
            return true;
        if (root->val != val)
            return false;
        return isSame(root->left, val) && isSame(root->right, val);
    }
    bool isUnivalTree(TreeNode *root)
    {
        if (!root)
            return true;
        return isSame(root, root->val);
    }
};
