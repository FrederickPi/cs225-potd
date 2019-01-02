#include "TreeNode.h"
#include <queue>
#include <iostream>

using namespace std;

int getHeight(TreeNode* curNode) {
	if (curNode == NULL) {return -1;}
	return 1 + max(getHeight(curNode->left_), getHeight(curNode->right_));
}

int getBalance(TreeNode* curNode) {
	return getHeight(curNode->left_) - getHeight(curNode->right_);
}

TreeNode* findLastUnbalanced(TreeNode* root) {
  	TreeNode* answer = NULL;
  	queue<TreeNode*> temp;
  	temp.push(root);
  	TreeNode* cur;
  	int tempBalance;
  	while(!temp.empty()) {
  		cur = temp.front();
  		temp.pop();
  		tempBalance = getBalance(cur);
      cur->balance_ = tempBalance;
  		if (tempBalance >= 2 || tempBalance <= -2) {
  			answer = cur;
  		}
  		if (cur->left_ != NULL) {temp.push(cur->left_);}
  		if (cur->right_ != NULL) {temp.push(cur->right_);}
  	}
  	return answer;
}

void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}

