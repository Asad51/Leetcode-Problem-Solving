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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 && t2){
        	TreeNode *root = new TreeNode(t1->val + t2->val);
        	root->left = mergeTrees(t1->left, t2->left);
        	root->right = mergeTrees(t1->right, t2->right);
        	return root;
        }
        
        if(t1)
        	return t1;
        return t2;
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
	TreeNode *t1 = new TreeNode(1);
	t1->left = new TreeNode(3);
	t1->right = new TreeNode(2);
	t1->left->left = new TreeNode(5);

	TreeNode *t2 = new TreeNode(2);
	t2->left = new TreeNode(1);
	t2->right = new TreeNode(3);
	t2->left->right = new TreeNode(4);
	t2->right->right = new TreeNode(7);

	TreeNode *root;
	Solution s;
	root = s.mergeTrees(t1, t2);
	showTree(root);
	return 0;
}