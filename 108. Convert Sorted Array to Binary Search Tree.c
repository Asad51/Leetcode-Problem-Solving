/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode Node;

Node *createNode(int n)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->val = n;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node *insert(int *nums, int l, int r)
{
    if (l > r)
        return NULL;
    int m = (r - l) / 2 + l;
    Node *node = createNode(nums[m]);
    node->left = insert(nums, l, m - 1);
    node->right = insert(nums, m + 1, r);
    return node;
}

Node *sortedArrayToBST(int *nums, int numsSize)
{
    Node *root = NULL;
    if (!numsSize)
        return root;
    root = insert(nums, 0, numsSize - 1);
    return root;
}
