#include "TreeNode.h"
#include <queue>

using namespace std;

TreeNode::RotationType balanceTree(TreeNode*& subroot) {
	TreeNode* lowest_unbalanced = NULL;
  	queue<TreeNode*> temp;
  	temp.push(subroot);
  	TreeNode* cur;
  	int tempBalance;
  	while(!temp.empty()) {
  		cur = temp.front();
  		temp.pop();
  		tempBalance = getHeight(cur->right_) - getHeight(cur->left_);
  		if (tempBalance >= 2 || tempBalance <= -2) {
  			lowest_unbalanced = cur;
  		}
  		if (cur->left_ != NULL) {temp.push(cur->left_);}
  		if (cur->right_ != NULL) {temp.push(cur->right_);}
  	}
  	if (leftHeavy(lowest_unbalanced)) {
  		if (leftHeavy(lowest_unbalanced->left_)) {return TreeNode::right;}
  		else {return TreeNode::leftRight;}
  	}
  	else {  // If lowest_unbalanced is right heavy
  		if (rightHeavy(lowest_unbalanced->right_)) {return TreeNode::left;}
  		else {return TreeNode::rightLeft;}
  	}
}
