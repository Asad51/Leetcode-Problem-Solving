/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int mDepth;

int min(int a, int b)
{
    return (a < b) ? a : b;
}

void findDepth(struct TreeNode *root, int depth)
{
    if (!root || depth >= mDepth)
        return;
    depth++;
    if (!root->left && !root->right)
    {
        mDepth = min(mDepth, depth);
        return;
    }
    findDepth(root->left, depth);
    findDepth(root->right, depth);
}

int minDepth(struct TreeNode *root)
{
    mDepth = INT_MAX;
    if (!root)
        return 0;
    findDepth(root, 0);
    return mDepth;
}
