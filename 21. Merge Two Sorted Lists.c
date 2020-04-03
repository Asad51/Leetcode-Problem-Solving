/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode Node;

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
    Node *dummy = malloc(sizeof(Node));
    dummy->val = 0;
    dummy->next = NULL;
    Node *tmp = dummy;
    while (l1 || l2)
    {
        if (!l2)
        {
            tmp->next = l1;
            l1 = l1->next;
        }
        else if (!l1)
        {
            tmp->next = l2;
            l2 = l2->next;
        }
        else
        {
            if (l1->val <= l2->val)
            {
                tmp->next = l1;
                l1 = l1->next;
            }
            else
            {
                tmp->next = l2;
                l2 = l2->next;
            }
        }
        tmp = tmp->next;
    }

    return dummy->next;
}
