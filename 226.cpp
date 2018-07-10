#include <bits/stdc++.h>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
    	if(root==NULL)
    		return NULL;
    	TreeNode *right = invertTree(root->right);
    	TreeNode *left = invertTree(root->left);

    	root->left = right;
    	root->right = left;
    	return root;
    }
};

void print(TreeNode* r){
    if(r==NULL)
    	return;
    print(r->left);
    print(r->right);
    cout<< r->val << endl;
}


int main(int argc, char const *argv[])
{
	TreeNode *root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->right = new TreeNode(7);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(9);

	//print(root);

	Solution s;
	//TreeNode* res = s.invertTree(root);
    print(s.invertTree(root));
	return 0;
}
