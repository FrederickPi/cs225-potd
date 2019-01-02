#include <vector>
#include <string>
#include "Hash.h"

using namespace std;

int hashFunction(string s, int M) {
	int answer = 0;
	for (auto c: s) {
		answer += (int) c;
	}
	return answer % M;
}

int countCollisions (int M, vector<string> inputs) {
	int collisions = 0;
	int cur_hash;
	vector<bool> hashExists(M);
	for (auto m: hashExists) {
		m = false;
	}

	for (auto i: inputs) {
		cur_hash = hashFunction(i, M);
		if (hashExists[cur_hash]) collisions++;
		else hashExists[cur_hash] = true;
	}
	return collisions;
}
