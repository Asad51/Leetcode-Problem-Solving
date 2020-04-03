/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution
{
public:
    vector<int> postorder(Node *root)
    {
        vector<int> res;
        stack<Node *> st;
        if (root)
            st.push(root);
        while (!st.empty())
        {
            Node *tp = st.top();
            st.pop();
            for (int i = 0; i < tp->children.size(); i++)
            {
                if (tp->children[i])
                    st.push(tp->children[i]);
            }
            res.push_back(tp->val);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
