/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct Node
{
    int val;
    struct Node *next;
};

struct Node *createNode(int n)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->val = n;
    newNode->next = NULL;
    return newNode;
}

struct Node *head, *current;

void findNum(struct TreeNode *root)
{
    if (!root)
        return;
    findNum(root->left);
    if (!head)
        head = current = createNode(root->val);
    else
    {
        current->next = createNode(root->val);
        current = current->next;
    }
    findNum(root->right);
}

int kthSmallest(struct TreeNode *root, int k)
{
    head = current = NULL;
    findNum(root);
    int i = 1;
    while (i < k && head)
    {
        i++;
        head = head->next;
    }
    return head->val;
}
