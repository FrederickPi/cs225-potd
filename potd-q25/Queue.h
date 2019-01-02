#ifndef _QUEUE_H
#define _QUEUE_H

#include <cstddef>

class Queue {
    public:
    	Queue();
        int size() const;
        bool isEmpty() const;
        void enqueue(int value);
        int dequeue();
    private:
    	class Node {
    		public:
    			Node * next;
    			Node * prev;
    			int data;
    	};
    	Node * head_;
    	Node * tail_;
};

#endif
