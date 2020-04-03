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
    bool isPalindrome(ListNode *head)
    {
        ListNode *newHead = NULL, *slow = head, *fast = head;
        while (slow && fast && fast->next)
        {
            ListNode *tmp = slow;
            slow = slow->next;
            fast = fast->next->next;
            tmp->next = newHead;
            newHead = tmp;
        }

        if (fast)
            slow = slow->next;
        head = slow;

        while (head && newHead)
        {
            if (head->val != newHead->val)
                return false;
            head = head->next;
            newHead = newHead->next;
        }
        return true;
    }
};
