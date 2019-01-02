#include <vector>
#include "Hash.h"

void doubleHashInput(std::vector<int> &v, int elem) {
	int idx = firstHash(elem, v.size());
	int jump = secondHash(elem);
	while (v[idx] != -1) {
		idx = (idx + jump) % v.size();
	}
  	v[idx] = elem;
}

int firstHash(int elem, int length) {
	return elem * 4 % length;
}

int secondHash(int elem) {
	return 3 - (elem % 3);
}

