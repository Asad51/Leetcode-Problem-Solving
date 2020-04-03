class Solution
{
public:
    string removeDuplicates(string S)
    {
        string res;
        stack<char> st;
        for (int i = 0; i < S.size(); i++)
        {
            if (st.size() > 0 && st.top() == S[i])
                st.pop();
            else
                st.push(S[i]);
        }
        while (!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        if (res.size() > 1)
            reverse(res.begin(), res.end());
        return res;
    }
};
