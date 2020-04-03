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
    int arr[101], n;

public:
    void findNodeValue(TreeNode *root)
    {
        if (!root)
            return;
        findNodeValue(root->left);
        arr[n++] = root->val;
        findNodeValue(root->right);
    }
    TreeNode *increasingBST(TreeNode *root)
    {
        n = 0;
        findNodeValue(root);
        //sort(arr, arr + n);
        TreeNode *head = new TreeNode(0);
        TreeNode *current = head;
        for (int i = 0; i < n; i++)
        {
            TreeNode *tmp = new TreeNode(arr[i]);
            current->right = tmp;
            current = current->right;
        }
        return head->right;
    }
};
