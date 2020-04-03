/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode Node;

struct ListNode *deleteDuplicates(struct ListNode *head)
{
    Node *tmp = head;
    while (tmp)
    {
        while (tmp->next && tmp->val == tmp->next->val)
        {
            tmp->next = tmp->next->next;
        }
        tmp = tmp->next;
    }
    return head;
}
