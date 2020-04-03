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
    ListNode *middleNode(ListNode *head)
    {
        int cnt = 0;
        ListNode *current = head;
        while (current)
        {
            cnt++;
            current = current->next;
        }
        int n = cnt / 2 + 1;
        cnt = 0;
        current = head;
        while (cnt < n - 1)
        {
            current = current->next;
            cnt++;
        }
        return current;
    }
};
