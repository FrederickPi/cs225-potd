#include "Node.h"
#include "iostream"

using namespace std;

Node *listUnion(Node *first, Node *second) {

  	// your code here
	Node * result = NULL;

	Node * cur_result = result;
	bool flag;

	while (first != NULL) {
		flag = false;
		while (cur_result != NULL) {
			if ( first->data_ == cur_result->data_) {
				flag = true;
				break;
			}
			cur_result = cur_result->next_;
		}
		if (!flag) {
			Node * new_node = new Node();
			new_node->data_ = first->data_;
			new_node->next_ = result;
			result = new_node;
		}
		cur_result = result;
		first = first->next_;
	}
	while (second != NULL) {
		flag = false;
		while (cur_result != NULL) {
			if ( second->data_ == cur_result->data_) {
				flag = true;
				break;
			}
			cur_result = cur_result->next_;
		}
		if (!flag) {
			Node * new_node = new Node();
			new_node->data_ = second->data_;
			new_node->next_ = result;
			result = new_node;
		}
		cur_result = result;
		second = second->next_;
	}
	return result;
}

Node::Node() {
    numNodes++;
}

Node::Node(Node &other) {
    this->data_ = other.data_;
    this->next_ = other.next_;
    numNodes++;
}

Node::~Node() {
    numNodes--;
}

int Node::numNodes = 0;
