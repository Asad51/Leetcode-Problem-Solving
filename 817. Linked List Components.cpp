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
    int numComponents(ListNode *head, vector<int> &G)
    {
        vector<int> check(10001);
        int cnt = 0;
        for (int i = 0; i < G.size(); i++)
            check[G[i]]++;
        while (head)
        {
            if (check[head->val] && (!head->next || !check[head->next->val]))
                cnt++;
            head = head->next;
        }
        return cnt;
    }
};
