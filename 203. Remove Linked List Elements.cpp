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
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *newHead = new ListNode(-1);
        newHead->next = head;
        ListNode *current = newHead;
        while (current)
        {
            if (current->next && current->next->val == val)
                current->next = current->next->next;
            else
                current = current->next;
        }
        return newHead->next;
    }
};
