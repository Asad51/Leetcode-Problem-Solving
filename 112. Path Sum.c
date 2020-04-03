/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool hasSum(struct TreeNode *root, int sum, int pathSum)
{
    if (!root)
        return false;
    pathSum += root->val;

    if (!root->left && !root->right)
    {
        if (sum == pathSum)
            return true;
        return false;
    }
    return hasSum(root->left, sum, pathSum) || hasSum(root->right, sum, pathSum);
}

bool hasPathSum(struct TreeNode *root, int sum)
{
    return hasSum(root, sum, 0);
}
