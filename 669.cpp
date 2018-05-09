#include "bits/stdc++.h"
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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
    	if(root==NULL)
    		return NULL;
    	if(root->val < L)
    		return trimBST(root->right, L, R);
    	if(root->val > R)
    		return trimBST(root->left, L, R);

    	TreeNode *t = new TreeNode(root->val);
    	t->left = trimBST(root->left, L, R);
    	t->right = trimBST(root->right, L, R);
    	return t;
    }
};

void showTree(TreeNode *root){
	if(root){
		cout<<root->val<<" ";
		showTree(root->left);
		showTree(root->right);
	}
}

int main(int argc, char const *argv[])
{
	TreeNode *t1 = new TreeNode(3);
	t1->left = new TreeNode(0);
	t1->right = new TreeNode(4);
	t1->left->right = new TreeNode(2);
	t1->left->right->left = new TreeNode(1);
	int l, r;
	cin>>l>>r;

	TreeNode *root;
	Solution s;
	root = s.trimBST(t1, l, r);
	showTree(root);
	return 0;
}