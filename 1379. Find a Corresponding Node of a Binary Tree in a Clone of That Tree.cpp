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
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        if (!cloned || !target)
            return NULL;
        if (target == original)
            return cloned;
        struct TreeNode *left = getTargetCopy(original->left, cloned->left, target);
        if (left)
            return left;
        struct TreeNode *right = getTargetCopy(original->right, cloned->right, target);
        if (right)
            return right;
        return NULL;
    }
};
