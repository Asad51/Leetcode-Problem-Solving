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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *tmp = head, *prev = NULL, *p = NULL;
        while (tmp)
        {
            if ((tmp->next && tmp->val == tmp->next->val) || (p && p->val == tmp->val))
            {
                p = tmp;
            }
            else
            {
                if (!prev)
                {
                    prev = tmp;
                    head = prev;
                }
                else
                {
                    prev->next = tmp;
                    prev = prev->next;
                }
            }
            tmp = tmp->next;
        }
        if (!prev)
            return NULL;
        else
            prev->next = NULL;
        return head;
    }
};
