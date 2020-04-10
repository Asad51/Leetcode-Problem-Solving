/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int n, *arr;

void getElements(struct TreeNode *root)
{
    if (!root)
        return;
    getElements(root->left);
    getElements(root->right);
    arr[n++] = root->val;
}

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int *getAllElements(struct TreeNode *root1, struct TreeNode *root2, int *returnSize)
{
    arr = malloc(10000 * sizeof(int));
    n = 0;
    getElements(root1);
    getElements(root2);
    qsort(arr, n, sizeof(int), compare);
    *returnSize = n;
    return arr;
}
