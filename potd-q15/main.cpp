#include "potd.h"
#include <iostream>
using namespace std;

int main() {
  // Test 1: An empty list
  Node * head = NULL;
  cout << stringList(head) << endl;

  Node * first = new Node();
  Node * second = new Node();
  Node * third = new Node();

  first->data_ = 1;
  second->data_ = 2;
  third->data_ = 3;
  cout << stringList(first) << endl;
  first->next_ = second;
  cout << stringList(first) << endl;
  second->next_ = third;
  cout << stringList(first) << endl;


  // Test 2: A list with exactly one node


  // Test 3: A list with more than one node

  return 0;
}
