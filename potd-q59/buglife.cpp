#include <vector>
#include <iostream>

// returns true if a counterexample is found
bool bugLife(int numBugs, vector<int> &b1, vector<int> &b2) {
    // code to make ignore the warning
    // delete and replace with your own.
    vector<int> bug_gender(numBugs + 2, -1);

    for (unsigned i = 0; i < b1.size(); i++) {
    	int b1_index = b1[i] + 1;
    	int b2_index = b2[i] + 1;

    	if (bug_gender[b1_index] < 0 && bug_gender[b2_index] < 0) {
    		bug_gender[b1_index] = 0;
    		bug_gender[b2_index] = 1;
    	}
    	else {
    		if (bug_gender[b1_index] < 0) {
    			bug_gender[b1_index] = bug_gender[b2_index] == 0 ? 1 : 0;
    		} 
    		else if (bug_gender[b2_index] < 0) {
    			bug_gender[b2_index] = bug_gender[b1_index] == 0 ? 1 : 0; 
    		}
    	}

    	if (bug_gender[b1_index] >= 0 && bug_gender[b2_index] >= 0 
    		&& bug_gender[b1_index] == bug_gender[b2_index]) {
    		return true;
    	}
    }
    return false;
}
