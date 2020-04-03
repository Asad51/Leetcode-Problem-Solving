int indexOf(char ch, char *order)
{
    for (int i = 0; order[i]; i++)
    {
        if (ch == order[i])
            return i;
    }
    return -1;
}

typedef struct Node
{
    struct Node *childs[26];
} Node;

Node *createNode()
{
    Node *node = malloc(sizeof(Node));
    for (int i = 0; i < 26; i++)
        node->childs[i] = NULL;
    return node;
}

Node *root;

bool insert(char *word, char *order)
{
    Node *tmp = root;
    for (int i = 0; word[i]; i++)
    {
        int idx = indexOf(word[i], order);
        if (!tmp->childs[idx])
            tmp->childs[idx] = createNode();

        for (int j = idx + 1; j < 26; j++)
        {
            if (tmp->childs[j])
                return false;
        }
        tmp = tmp->childs[idx];
    }
    for (int i = 0; i < 26; i++)
    {
        if (tmp->childs[i])
            return false;
    }
    return true;
}

bool isAlienSorted(char **words, int wordsSize, char *order)
{
    root = createNode();
    for (int i = 0; i < wordsSize; i++)
    {
        if (!insert(words[i], order))
            return false;
    }
    return true;
}
