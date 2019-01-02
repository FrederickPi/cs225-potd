#include "MinHeap.h"
#include <iostream>

using namespace std;

vector<int> lastLevel(MinHeap & heap) {
	unsigned int idx = 0;
	while ( (heap.elements.size() - 1) > (idx * 2 + 1) ) {
		idx = idx * 2 + 1;
	}
	vector<int> answer;
	for (unsigned int i = idx + 1; i < heap.elements.size(); i++) {
		answer.push_back(heap.elements[i]);
	}
	return answer;
}
