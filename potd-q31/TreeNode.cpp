#include "TreeNode.h"
#include <algorithm>

using namespace std;

bool isHeightBalanced(TreeNode* root) {
	int balance = getHeight(root->left_) - getHeight(root->right_);
  	return balance <= 1 && balance >= -1;
}

int getHeight(TreeNode* root) {
	if (root == NULL) {return -1;}
	return 1 + max(getHeight(root->left_), getHeight(root->right_));
}

void deleteTree(TreeNode* root)
{
  	if (root == NULL) return;
  	deleteTree(root->left_);
  	deleteTree(root->right_);
  	delete root;
  	root = NULL;
}

