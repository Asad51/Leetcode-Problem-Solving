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
    int sum[10000], deepest;

public:
    void findSum(TreeNode *root, int depth)
    {
        if (!root)
            return;
        sum[depth] += root->val;
        deepest = max(deepest, depth);
        findSum(root->left, depth + 1);
        findSum(root->right, depth + 1);
    }

    int deepestLeavesSum(TreeNode *root)
    {
        deepest = 0;
        for (int i = 0; i < 10000; i++)
            sum[i] = 0;
        findSum(root, 0);
        return sum[deepest];
    }
};
