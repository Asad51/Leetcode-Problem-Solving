struct Node
{
    int val;
    Node *prev, *next;
    Node(int v) : val(v), prev(NULL), next(NULL){};
};

class CustomStack
{
    int maxSize, size;
    Node *head, *tail;

public:
    CustomStack(int maxSize)
    {
        this->maxSize = maxSize;
        size = 0;
        head = tail = NULL;
    }

    void push(int x)
    {
        if (size == maxSize)
            return;

        if (!head || !tail)
            head = tail = new Node(x);
        else
        {
            Node *node = new Node(x);
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        size++;
    }

    int pop()
    {
        if (!size || !tail)
            return -1;
        int val = tail->val;
        tail = tail->prev;
        if (!tail)
            head = tail;
        else
            tail->next = NULL;
        size--;
        return val;
    }

    void increment(int k, int val)
    {
        Node *tmp = head;
        while (k-- && tmp)
        {
            tmp->val += val;
            tmp = tmp->next;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
