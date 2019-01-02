#include "TreeNode.h"
#include <algorithm>


void rightRotate(TreeNode* root) {
	TreeNode * temp = root->left_;
    TreeNode * tempRight = temp->right_;

    root->left_ = tempRight;
    
    temp->right_ = root;
    temp->parent_ = root->parent_;
    if (root->parent_ != NULL) {
    	if (root->parent_->left_ == root) {root->parent_->left_ = temp;}
    	else {root->parent_->right_ = temp;}
    }

    root->parent_ = temp;
    
    root->left_ = tempRight;
    if (tempRight != NULL) {tempRight->parent_ = root;}
}


void leftRotate(TreeNode* root) {
	TreeNode * temp = root->right_;
    TreeNode * tempLeft = temp->left_;

    root->right_ = tempLeft;
    
    temp->left_ = root;
    temp->parent_ = root->parent_;
    if (root->parent_ != NULL) {
    	if (root->parent_->right_ == root) {root->parent_->right_ = temp;}
    	else {root->parent_->left_ = temp;}
    }

    root->parent_ = temp;
    
    root->right_ = tempLeft;
    if (tempLeft != NULL) {tempLeft->parent_ = root;}
}



void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}

