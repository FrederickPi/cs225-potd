// your code here
#include "Food.h"
#include "q5.h"
#include <iostream>

using namespace std;


int main() {
	Food * apples = new Food();
	cout << "You have " << apples->get_quantity() << " " << apples->get_name() << endl;
	increase_quantity(apples);
	return 0;
}