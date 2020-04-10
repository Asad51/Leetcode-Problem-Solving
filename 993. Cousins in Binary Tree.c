/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int p1, p2, d1, d2;

void findDepth(struct TreeNode *root, int x, int y, int p, int dp)
{
    if (d1 > -1 && d2 > -1)
        return;
    if (!root)
        return;
    if (root->val == x)
    {
        p1 = p;
        d1 = dp;
    }

    if (root->val == y)
    {
        p2 = p;
        d2 = dp;
    }

    findDepth(root->left, x, y, root->val, dp + 1);
    findDepth(root->right, x, y, root->val, dp + 1);
}

bool isCousins(struct TreeNode *root, int x, int y)
{
    p1 = p2 = d1 = d2 = -1;
    findDepth(root, x, y, -1, 0);

    return (p1 != p2) && (d1 == d2);
}
