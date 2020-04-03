typedef struct Node
{
    bool isLeaf;
    int idx;
    struct Node *childs[10];
} Node;

Node *createNode()
{
    Node *node = malloc(sizeof(Node));
    node->isLeaf = false;
    node->idx = -1;
    for (int i = 0; i < 10; i++)
        node->childs[i] = NULL;
    return node;
}

bool insert(Node *tmp, long n, int idx, int k)
{
    n = (n < 0) ? n * -1 : n;
    if (!n)
    {
        if (!tmp->childs[n])
            tmp->childs[n] = createNode();
        tmp = tmp->childs[n];
    }

    while (n)
    {
        int r = n % 10;
        n /= 10;
        if (!tmp->childs[r])
            tmp->childs[r] = createNode();
        tmp = tmp->childs[r];
    }

    if (tmp->isLeaf && (idx - tmp->idx <= k))
        return true;

    tmp->isLeaf = true;
    tmp->idx = idx;

    return false;
}

bool containsNearbyDuplicate(int *nums, int numsSize, int k)
{
    Node *negRoot = createNode(), *posRoot = createNode();
    bool isDuplicate = false;

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] < 0)
            isDuplicate = insert(negRoot, nums[i], i, k);
        else
            isDuplicate = insert(posRoot, nums[i], i, k);
        if (isDuplicate)
            break;
    }
    return isDuplicate;
}
