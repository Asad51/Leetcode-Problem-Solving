/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int getDecimalValue(struct ListNode *head)
{
    int i = 0, n = 0;
    struct ListNode *tmp = head;
    while (tmp)
    {
        tmp = tmp->next;
        i++;
    }

    while (head)
    {
        n += head->val * pow(2, --i);
        head = head->next;
    }

    return n;
}
