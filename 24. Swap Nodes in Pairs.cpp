/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *tmp = head, *prev = NULL;
        while (tmp && tmp->next)
        {
            ListNode *tmpNextNext = tmp->next->next, *tmpNext = tmp->next;
            if (!prev)
            {
                head = tmp->next;
            }
            else
            {
                prev->next = tmpNext;
            }
            tmp->next = tmpNextNext;
            tmpNext->next = tmp;
            prev = tmp;
            tmp = tmpNextNext;
        }
        return head;
    }
};
