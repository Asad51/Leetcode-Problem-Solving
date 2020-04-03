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
    TreeNode *insert(TreeNode *root, int val)
    {
        if (!root)
            return new TreeNode(val);
        if (val > root->val)
        {
            TreeNode *tmp = new TreeNode(val);
            tmp->left = root;
            return tmp;
        }
        else
            root->right = insert(root->right, val);
        return root;
    }

    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        TreeNode *head = NULL;
        for (int i = 0; i < nums.size(); i++)
        {
            head = insert(head, nums[i]);
        }
        return head;
    }
};
