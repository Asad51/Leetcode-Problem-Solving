/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode Node;

Node *createNode(int val)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    Node *dummy = malloc(sizeof(Node));
    dummy->val = 0;
    dummy->next = NULL;
    Node *tmp = dummy;
    int carry = 0, sum = 0;

    while (l1 || l2)
    {
        if (!l2)
        {
            sum = carry + l1->val;
            l1 = l1->next;
        }
        else if (!l1)
        {
            sum = carry + l2->val;
            l2 = l2->next;
        }
        else
        {
            sum = carry + l1->val + l2->val;
            l1 = l1->next;
            l2 = l2->next;
        }
        tmp->next = createNode(sum % 10);
        tmp = tmp->next;
        carry = sum / 10;
    }
    if (carry)
        tmp->next = createNode(carry);
    return dummy->next;
}
