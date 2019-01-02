#include "potd.h"

// Your code here!
double sum(vector<double>::iterator start, vector<double>::iterator end) {
	double answer = 0;
	for (auto i = start; i != end; i++) {
		answer += *i;
	}
	return answer;
}

vector<double>::iterator max_iter(vector<double>::iterator start, vector<double>::iterator end) {
	vector<double>::iterator result = start;
	for (auto i = start; i != end; i++) {
		if (*i > *result) result = i;
	}
	return result;
}

void sort_vector(vector<double>::iterator start, vector<double>::iterator end) {
	for (auto i = start; i != end; i++) {
		vector<double>::iterator j = max_iter(i, end);
		if (*i != *j) {
			double temp = *i;
			*i = *j;
			*j = temp;
		}
	}
}