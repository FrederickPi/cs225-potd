#include "potd.h"
#include <iostream>

using namespace std;

int flag = 0;
int counter = -1;

string stringList(Node *head) {
	string cur_addition = "";
    if (flag == 0 && head == NULL) {
    	return "Empty list";
    }
    if (head == NULL) {
    	flag = 0;
    	counter = -1;
    	return "";
    }
    if (flag) { cur_addition = cur_addition + " -> "; }
    flag = 1;
    counter++;
    return cur_addition + "Node " + to_string(counter) + ": " + to_string(head->data_) + stringList(head->next_);
}
