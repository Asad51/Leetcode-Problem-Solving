#define MAXN 10001

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
    int n;
    TreeNode *nodes[MAXN];
    void sortNodes(TreeNode *root)
    {
        if (!root)
            return;
        if (!root->left && !root->right)
        {
            nodes[n++] = root;
            return;
        }
        if (root->left)
            sortNodes(root->left);
        nodes[n++] = root;
        if (root->right)
            sortNodes(root->right);
    }

    TreeNode *createBST(int l, int r)
    {
        if (l > r)
            return NULL;
        int m = (l + r) / 2;
        TreeNode *root = nodes[m];
        root->left = createBST(l, m - 1);
        root->right = createBST(m + 1, r);
        return root;
    }

public:
    TreeNode *balanceBST(TreeNode *root)
    {
        n = 0;
        sortNodes(root);
        return createBST(0, n - 1);
    }
};
