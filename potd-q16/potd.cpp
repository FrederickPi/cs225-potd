#include "potd.h"
#include <iostream>

using namespace std;

void insertSorted(Node **head, Node *insert) {

	if (*head == NULL) {
		*head = insert;
		return;
	}

	Node *temp = *head;
	
	if (temp->data_ > insert->data_) {
		*head = insert;
		insert->next_ = temp;
		return;
	}

	//temp = temp->next_;
	
	while(temp->next_ != NULL) {
		if (temp->next_->data_ > insert->data_) {
			insert->next_ = temp->next_;
			temp->next_ = insert;
			return;
		}
		temp = temp->next_;
	}

	(*head)->next_ = insert;
	return;
}
