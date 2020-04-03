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
    bool isFound;
    TreeNode *head;
    map<int, int> mp;

public:
    void findNum(TreeNode *root, int target)
    {
        if (!root || isFound)
            return;
        if (mp[target - root->val])
        {
            isFound = true;
            return;
        }
        mp.insert(make_pair(root->val, 1));
        findNum(root->left, target);
        if (mp[target - root->val])
        {
            isFound = true;
            return;
        }
        findNum(root->right, target);
    }

    bool findTarget(TreeNode *root, int k)
    {
        isFound = false;
        head = root;
        findNum(root, k);
        return isFound;
    }
};
