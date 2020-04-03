typedef struct Node
{
    bool isLeaf;
    struct Node *childs[10];
} Node;

Node *createNode()
{
    Node *node = malloc(sizeof(Node));
    node->isLeaf = false;
    for (int i = 0; i < 10; i++)
        node->childs[i] = NULL;
    return node;
}

bool insert(Node *root, int num)
{
    if (!num)
    {
        if (root->childs[num] && root->childs[num]->isLeaf)
            return true;
        else if (!root->childs[num])
            root->childs[num] = createNode();
        root->childs[num]->isLeaf = true;
    }

    num = abs(num);
    while (num)
    {
        int rem = num % 10;
        num /= 10;
        if (!root->childs[rem])
            root->childs[rem] = createNode();
        root = root->childs[rem];
    }
    if (root->isLeaf)
        return true;
    else
        root->isLeaf = true;

    return false;
}

bool containsDuplicate(int *nums, int numsSize)
{
    Node *posRoot = createNode(), *negRoot = createNode();
    bool isDuplicate = false;

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] < 0)
            isDuplicate = insert(negRoot, nums[i]);
        else
            isDuplicate = insert(posRoot, nums[i]);
        if (isDuplicate)
            break;
    }
    return isDuplicate;
}
