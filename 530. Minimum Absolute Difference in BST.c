/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

long max(long a, long b)
{
    return (a > b) ? a : b;
}

long min(long a, long b)
{
    return (a < b) ? a : b;
}

long Abs(long a, long b)
{
    return (a > b) ? a - b : b - a;
}

typedef struct Node
{
    long mx;
    long mn;
} Node;

long mn;

Node findMinDiff(struct TreeNode *root)
{
    Node node = {INT_MIN, INT_MAX};
    if (!root)
        return node;
    Node left = findMinDiff(root->left);
    Node right = findMinDiff(root->right);

    mn = min(mn, Abs(root->val, left.mx));
    mn = min(mn, Abs(root->val, right.mn));

    node.mn = min(root->val, left.mn);
    node.mx = max(root->val, right.mx);

    return node;
}

int getMinimumDifference(struct TreeNode *root)
{
    mn = INT_MAX;
    Node node = findMinDiff(root);

    return mn;
}
