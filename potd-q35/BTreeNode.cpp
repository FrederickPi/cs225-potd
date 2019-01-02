#include <vector>
#include "BTreeNode.h"


BTreeNode* find(BTreeNode* root, int key) {
	for (unsigned i = 0; i < root->elements_.size(); i++) {
		if (root->elements_[i] == key) {return root;}
		if (root->elements_[i] > key && !(root->is_leaf_)) {return find(root->children_[i], key);}
	}
	if (key > root->elements_[root->elements_.size() - 1] && !(root->is_leaf_)) {
		return find(root->children_[root->children_.size() - 1], key);
	}
  	return NULL;
}
