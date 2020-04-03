struct Node
{
    int val;
    Node *next;
    Node(int v) : val(v), next(NULL){};
};

class MyLinkedList
{
    Node *head, *tail;

public:
    /** Initialize your data structure here. */
    MyLinkedList()
    {
        head = tail = NULL;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index)
    {
        int i = 0;
        Node *tmp = head;
        while (tmp && i < index)
        {
            tmp = tmp->next;
            i++;
        }
        if (tmp)
            return tmp->val;
        return -1;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val)
    {
        Node *newNode = new Node(val);
        if (!tail || !head)
            head = tail = newNode;
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val)
    {
        Node *newNode = new Node(val);
        if (!tail || !head)
            head = tail = newNode;
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val)
    {
        if (!head || index == 0)
        {
            addAtHead(val);
            return;
        }
        Node *newNode = new Node(val), *tmp = head;
        int i = 0;
        while (tmp && i < index - 1)
        {
            tmp = tmp->next;
            i++;
        }
        if (tmp)
        {
            Node *t = tmp->next;
            tmp->next = newNode;
            newNode->next = t;
            if (!t)
                tail = newNode;
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index)
    {
        if (index == 0)
        {
            head = head->next;
            if (!head)
                tail = head;
            return;
        }
        int i = 0;
        Node *tmp = head;
        while (tmp && i < index - 1)
        {
            tmp = tmp->next;
            i++;
        }

        if (tmp && tmp->next)
        {
            Node *t = tmp->next->next;
            tmp->next = t;
            if (!t)
                tail = tmp;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
