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
    vector<int> nextLargerNodes(ListNode *head)
    {
        vector<int> result;
        stack<pair<int, int>> st;
        for (int i = 0; head; head = head->next)
        {
            while (st.size() && head->val > st.top().first)
            {
                result[st.top().second] = head->val;
                st.pop();
            }
            st.push({head->val, i++});
            result.push_back(0);
        }
        return result;
    }
};
