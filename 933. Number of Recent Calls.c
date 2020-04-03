typedef struct Node
{
    int tm;
    struct Node *next;
} Node;

Node *createNode(int t)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->tm = t;
    return newNode;
}

typedef struct
{
    Node *root, *last;
    int cnt;
} RecentCounter;

RecentCounter *recentCounterCreate()
{
    RecentCounter *newCounter = malloc(sizeof(RecentCounter));
    newCounter->root = newCounter->last = NULL;
    newCounter->cnt = 0;
    return newCounter;
}

int recentCounterPing(RecentCounter *obj, int t)
{
    if (!obj)
        return NULL;

    Node *tmp = createNode(t);
    obj->cnt++;
    if (!obj->root)
    {
        obj->root = obj->last = tmp;
        return obj->cnt;
    }
    obj->last->next = tmp;
    obj->last = obj->last->next;

    while (obj->root && (t - obj->root->tm) > 3000)
    {
        printf("%d\n", (t - obj->root->tm));
        obj->root = obj->root->next;
        obj->cnt--;
    }
    return obj->cnt;
}

void recentCounterFree(RecentCounter *obj)
{
    free(obj);
}

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);
 
 * recentCounterFree(obj);
*/
