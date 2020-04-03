#define MAXC 26
#define MAXL 101
#define MAXW 1001

struct TrieNode
{
    int isLeaf;
    struct TrieNode *childs[MAXC];
};

typedef struct TrieNode TrieNode;

TrieNode *createNode()
{
    TrieNode *newNode = malloc(sizeof(TrieNode));
    newNode->isLeaf = 0;
    for (int i = 0; i < MAXC; i++)
        newNode->childs[i] = NULL;

    return newNode;
}

TrieNode *root;

void insertRoot(char *str)
{
    TrieNode *tmp = root;
    for (int i = 0; str[i]; i++)
    {
        int index = str[i] - 'a';
        if (!tmp->childs[index])
            tmp->childs[index] = createNode();
        tmp = tmp->childs[index];
    }
    tmp->isLeaf = 1;
}

char *findRoot(char *str)
{
    char *s = malloc(MAXL * sizeof(char));
    TrieNode *tmp = root;
    //printf("%s\n", str);

    for (int i = 0; str[i] && i < MAXL; i++)
    {
        int index = str[i] - 'a';
        if (!tmp->childs[index])
            return str;
        s[i] = str[i];
        tmp = tmp->childs[index];
        if (tmp->isLeaf)
        {
            s[i + 1] = '\0';
            return s;
        }
    }
    return str;
}

char *replaceWords(char **dict, int dictSize, char *s)
{
    root = createNode();

    for (int i = 0; i < dictSize; i++)
        insertRoot(dict[i]);

    char *tmp = malloc(MAXW * sizeof(char)), *ret = malloc(MAXW * sizeof(char)), *str = malloc(MAXW * MAXW * sizeof(char));
    int i = 0, j = 0;

    for (int k = 0; s[k]; k++)
    {
        if (s[k] != ' ')
            tmp[j++] = s[k];
        if (s[k] == ' ' || s[k + 1] == '\0')
        {
            tmp[j] = '\0';
            ret = findRoot(tmp);

            //printf("%s %s\n", tmp, ret);
            for (int l = 0; ret[l]; l++)
                str[i++] = ret[l];
            j = 0;
            if (s[k] == ' ')
                str[i++] = ' ';
        }
    }

    str[i] = '\0';
    return str;
}
