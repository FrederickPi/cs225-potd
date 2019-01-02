// your code here!
#include <cmath>
#include <iostream>

using namespace std;

namespace potd {
	int* raise(int* arr) {
		int array_size = 0;
		while (arr[array_size] > 0) {
			array_size++;
		}
		array_size++;
		cout << array_size << endl;
		int* new_array = new int(array_size);
		cout << sizeof(new_array) / sizeof(new_array[0]) << endl;
		int current, next;
		for (int index = 0; index < array_size; index++) {
			current = arr[index];
			if (index == array_size - 1 || index == array_size - 2) {
				new_array[index] = current;
			}
			else {
				next = arr[index + 1];
				new_array[index] = pow(current, next);
			}
			cout << new_array[index] << endl;
		} 
		return new_array;
	}
}