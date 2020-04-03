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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *current = NULL, *tmp = NULL;
        while (head)
        {
            tmp = head;
            head = head->next;
            tmp->next = current;
            current = tmp;
        }
        return current;
    }
};
