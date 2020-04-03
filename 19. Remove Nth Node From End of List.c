/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode Node;

struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    Node *tmp = head;
    int cnt = 0;
    while (tmp)
    {
        cnt++;
        tmp = tmp->next;
    }

    n = cnt - n;
    tmp = head;
    cnt = 0;
    if (n == 0)
        return head->next;
    while (tmp && cnt < n - 1)
    {
        tmp = tmp->next;
        cnt++;
    }
    tmp->next = tmp->next->next;
    return head;
}
