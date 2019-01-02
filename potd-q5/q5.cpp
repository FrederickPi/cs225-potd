// your code here
#include <string>
#include <iostream>
#include "q5.h"
#include "Food.h"

using namespace std;

void increase_quantity(Food * food_item) {
	int num_food = food_item->get_quantity();
	food_item->set_quantity(num_food + 1);
	cout << "You have " << num_food + 1 << " " << food_item->get_name() << endl;
}
