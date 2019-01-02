#include "Node.h"

using namespace std;

void mergeList(Node *first, Node *second) {
  	if (second == NULL) {return;}
  	Node * temp2;
  	while (first != NULL) {
  		if (second != NULL){ 
  			if (first->next_ == NULL) {
  				first->next_ = second;
  				return;
  			}
  			temp2 = second->next_;
  			second->next_ = first->next_;
  			first->next_ = second;
  			second = temp2;
		}
  		first = first->next_->next_;
  	}
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

