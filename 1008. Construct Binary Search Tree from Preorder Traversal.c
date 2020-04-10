/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *createNode(int n)
{
    struct TreeNode *node = malloc(sizeof(struct TreeNode));
    node->val = n;
    node->left = node->right = NULL;
    return node;
}

struct TreeNode *insert(struct TreeNode *root, int n)
{
    if (!root)
        return createNode(n);
    if (root->val > n)
        root->left = insert(root->left, n);
    else
        root->right = insert(root->right, n);
    return root;
}

struct TreeNode *bstFromPreorder(int *preorder, int preorderSize)
{
    struct TreeNode *root = NULL;
    for (int i = 0; i < preorderSize; i++)
        root = insert(root, preorder[i]);

    return root;
}
