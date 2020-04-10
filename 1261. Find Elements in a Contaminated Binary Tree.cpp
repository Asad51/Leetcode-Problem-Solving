/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements
{
    TreeNode *head;
    int arr[1000001];
    void recoverTree(TreeNode *root, int val)
    {
        if (!root)
            return;
        if (val > 1000000)
            return;
        arr[val] = 1;
        root->val = val;
        recoverTree(root->left, 2 * val + 1);
        recoverTree(root->right, 2 * val + 2);
    }

public:
    FindElements(TreeNode *root)
    {
        head = root;
        for (int i = 0; i < 1000001; i++)
            arr[i] = 0;
        recoverTree(root, 0);
    }

    bool find(int target)
    {
        return arr[target] == 1;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
