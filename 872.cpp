#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    vector<int>v1, v2;
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        v1.clear();
        v2.clear();
        findLeaf(root1, v1);
        findLeaf(root2, v2);
        
        if(v1.size()!=v2.size())
            return false;
        for(int i=0; i<v1.size(); i++){
            if(v1[i]!=v2[i])
                return false;
        }
        //cout<<v1.size();
        return true;
    }
    
    void findLeaf(TreeNode *root, vector<int>& v ){
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL){
            v.push_back(root->val);
            return;
        }
        findLeaf(root->left, v);
        findLeaf(root->right, v);
    }
};

int main(int argc, char const *argv[])
{
    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(2);
    Solution s;
    if(s.leafSimilar(t1, t2))
        cout<<"True\n";
    else
        cout<<"false\n";
    return 0;
}