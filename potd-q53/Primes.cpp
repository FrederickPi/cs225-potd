#include <vector>
#include <math.h>
#include "Primes.h"

std::vector<int> *genPrimes(int M) {
    std::vector<int> *v = new std::vector<int>();
    std::vector<int> all_numbers;
    // O(M), M = number provided
    for (int i = 2; i <= M; i++)
    	all_numbers.push_back(i);
    // O(sqrt(M) * O(M)) = O(M^(3/2))
    // This is what it seems, however I read somewhere it is...
    // O(MlogM)
    for (unsigned i = 0; i < sqrt(M) - 2; i++) {
    	if (all_numbers[i] == -1) continue;
    	int jump_size = all_numbers[i];
    	for (unsigned j = i + jump_size; j < all_numbers.size(); j += jump_size) {
    		all_numbers[j] = -1;
    	}
    }
    // O(M)
    for (unsigned i = 0; i < all_numbers.size(); i++) {
    	if (all_numbers[i] != -1)
    		v->push_back(all_numbers[i]);
    }
    return v;
}

