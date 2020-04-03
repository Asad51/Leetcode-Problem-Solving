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
    vector<ListNode *> splitListToParts(ListNode *root, int k)
    {
        vector<ListNode *> res;
        int n = 0;
        ListNode *tmp = root;
        while (tmp)
        {
            n++;
            tmp = tmp->next;
        }

        int m = n / k;
        tmp = root;
        for (int i = 0; i < k; i++)
        {
            ListNode *tHead = tmp, *t = tHead;
            int j = 1;
            while (tmp && j < m)
            {
                t = t->next;
                tmp = tmp->next;
                j++;
            }
            if (tmp && (i < (n % k)) && j <= m)
            {
                t = t->next;
                tmp = tmp->next;
            }
            if (t && tmp)
            {
                tmp = tmp->next;
                t->next = NULL;
            }
            res.push_back(tHead);
        }
        return res;
    }
};
