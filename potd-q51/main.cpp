#include "potd.h"
#include <vector>
#include <iostream>
using namespace std;

int main() {
	vector<string> common = topThree("in1.txt");
	for (auto str: common)
		cout << str << endl;
	return 0;
}
