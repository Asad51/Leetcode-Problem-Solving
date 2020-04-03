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
    vector<int> preorder(Node *root)
    {
        stack<Node *> st;
        vector<int> res;
        if (!root)
            return res;
        st.push(root);
        while (!st.empty())
        {
            Node *tp = st.top();
            res.push_back(tp->val);
            st.pop();
            for (int i = tp->children.size() - 1; i >= 0; i--)
            {
                if (tp->children[i])
                    st.push(tp->children[i]);
            }
        }
        return res;
    }
};
