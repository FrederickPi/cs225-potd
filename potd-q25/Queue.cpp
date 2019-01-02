#include "Queue.h"
#include <iostream>

using namespace std;

Queue::Queue() {
	head_ = NULL;
	tail_ = NULL;
}

// `int size()` - returns the number of elements in the stack (0 if empty)
int Queue::size() const {
	int count = 0;
   	Queue::Node * temp = head_;
   	while (temp != NULL) {
   		count++;
   		temp = temp->next;
   	}
   	return count;
}

// `bool isEmpty()` - returns if the list has no elements, else false
bool Queue::isEmpty() const {
  	return (head_ == NULL);
}

// `void enqueue(int val)` - enqueue an item to the queue in O(1) time
void Queue::enqueue(int value) {
	Queue::Node * newNode = new Queue::Node();
	if (isEmpty()) {tail_ = newNode;}
	newNode->data = value;
	newNode->next = head_;
	newNode->prev = NULL;
	if (head_ != NULL) {head_->prev = newNode;}
	head_ = newNode;
}

// `int dequeue()` - removes an item off the queue and returns the value in O(1) time
int Queue::dequeue() {
	if (head_ == tail_) {
		int temp = head_->data;
		delete head_;
		head_ = NULL;
		tail_ = NULL;
		return temp;
	}
	if (head_ == NULL) {return -1;}
	int temp = tail_->data;
	tail_ = tail_->prev;
	delete tail_->next;
	tail_->next = NULL;
	return temp;
}
