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
    int sum, bits[32];

    int toDecimal(int n)
    {
        int s = 0;
        for (int i = n; i >= 0; i--)
            s += (bits[i] * pow(2, n - i));
        return s;
    }

    void calculateSum(TreeNode *head, int i)
    {
        if (!head)
            return;
        bits[i] = head->val;
        if (!head->left && !head->right)
        {
            sum += toDecimal(i);
            return;
        }
        calculateSum(head->left, i + 1);
        calculateSum(head->right, i + 1);
    }

public:
    int sumRootToLeaf(TreeNode *root)
    {
        sum = 0;
        calculateSum(root, 0);
        return sum;
    }
};
