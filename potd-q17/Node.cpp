#include "Node.h"
#include <iostream>

using namespace std;

void sortList(Node **head) {  // This is selection sort algorithm
  	if ( (*head) == NULL || (*head)->next_ == NULL) {return;}

  	// find minimum node, and put in front of first node
	Node * prev = NULL;
	Node * min = (*head);
	Node * cur = (*head);
	while (cur->next_ != NULL) {
		if (min->data_ > cur->next_->data_) {
			min = cur->next_;
			prev = cur;
		}
		cur = cur->next_;
	}ak
	// put in front of first node
	if (min != *head) {
		prev->next_ = min->next_;
		min->next_ = *head;
		*head = min;
	}
  	sortList(&((*head)->next_));
  	return;
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

