#define MAXHT 60000

typedef struct
{
    int val;
    int frq;
} Frequency;

Frequency hashTable[MAXHT];

unsigned int getHash(int m)
{
    unsigned int hash = 5381;

    while (m)
    {
        int r = m % 10;
        m /= 10;
        hash = (((hash << 7) + hash) + r) % MAXHT;
    }
    return hash % MAXHT;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void insert(int m)
{
    unsigned int hash = getHash(m);
    while (hashTable[hash].frq)
    {
        if (hashTable[hash].val == m)
        {
            hashTable[hash].frq++;
            return;
        }
        hash = (hash + 1) % MAXHT;
    }
    hashTable[hash].frq++;
    hashTable[hash].val = m;
}

int find(int m)
{
    unsigned int hash = getHash(m);
    while (hashTable[hash].frq)
    {
        if (hashTable[hash].val == m)
            return hashTable[hash].frq;
        hash = (hash + 1) % MAXHT;
    }
    return 0;
}

int findLHS(int *nums, int numsSize)
{
    int ans = 0;
    for (int i = 0; i < MAXHT; i++)
        hashTable[i].frq = 0;
    for (int i = 0; i < numsSize; i++)
        insert(nums[i]);

    for (int i = 0; i < numsSize; i++)
    {
        int f1 = find(nums[i]), f2 = find(nums[i] - 1);
        if (f2)
            ans = max(ans, f1 + f2);
    }
    return ans;
}
