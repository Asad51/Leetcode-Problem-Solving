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
    int sum = 0;

public:
    void calculate(TreeNode *head)
    {
        if (!head || (!head->left && !head->right))
            return;
        if (head->val % 2 == 0)
        {
            if (head->left)
            {
                if (head->left->left)
                    sum += head->left->left->val;
                if (head->left->right)
                    sum += head->left->right->val;
                calculate(head->left);
            }
            if (head->right)
            {
                if (head->right->left)
                    sum += head->right->left->val;
                if (head->right->right)
                    sum += head->right->right->val;
                calculate(head->right);
            }
        }
        else
        {
            calculate(head->left);
            calculate(head->right);
        }
    }

    int sumEvenGrandparent(TreeNode *root)
    {
        calculate(root);
        return sum;
    }
};
