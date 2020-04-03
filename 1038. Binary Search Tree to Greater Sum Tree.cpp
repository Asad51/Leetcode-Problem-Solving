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
    int bstToGt(TreeNode *root, int sum)
    {
        if (!root)
            return sum;
        sum = bstToGt(root->right, sum) + root->val;
        root->val = sum;
        return bstToGt(root->left, sum);
    }

    TreeNode *bstToGst(TreeNode *root)
    {
        if (!root)
            return root;
        bstToGt(root, 0);
        return root;
    }
};
