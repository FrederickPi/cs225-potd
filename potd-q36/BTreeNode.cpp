#include <vector>
#include "BTreeNode.h"

using namespace std;

vector<int> traverse(BTreeNode* root) {
    vector<int> answer;
    traverse(root, answer);
    return answer;
}

void traverse(BTreeNode* root, vector<int> & answer) {
	for (unsigned i = 0; i < root->elements_.size(); i++) {
		if (!root->is_leaf_) {traverse(root->children_[i], answer);}
		answer.push_back(root->elements_[i]);
	}
	if (!root->is_leaf_) {traverse(root->children_.back(), answer);}
}