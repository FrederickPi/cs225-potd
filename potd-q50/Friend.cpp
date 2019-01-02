#include "Friend.h"

using namespace std;

int find(int x, vector<int>& parents) {
   // your code
	return 0;
}

int findCircleNum(vector<vector<int>>& M) {
    vector<int> dJS;

    for (unsigned i = 0; i < M.size(); i++) 
    	dJS.push_back(-1);

    for (unsigned i = 0; i < M.size(); i++) {
    	for (unsigned j = 0; j < M[i].size(); j++) {
    		if (M[i][j] == 1) {
    			int a = i;
    			int b = j;
    			while (dJS[a] >= 0)
					a = dJS[a];
				while (dJS[b] >= 0) 
					b = dJS[b];
				int newSize = dJS[a] + dJS[b];
				if (dJS[a] <= dJS[b]) {
					dJS[b] = a;
					dJS[a] = newSize;
				}
				else {
					dJS[a] = b;
					dJS[b] = newSize;
				}
    		}
    	}
    }

    int answer = 0;
    for (auto i: dJS)
    	if (i < 0) answer++;
    
    return answer;
}
