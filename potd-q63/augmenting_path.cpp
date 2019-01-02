#include "network_flow.cpp"

bool hasAugmentingPath(ResidualNetwork r) {
    // DFS
    stack<int> s;
    s.push(r.source);
    while (!s.empty()) {
    	int cur = s.top();
    	s.pop();
    	if (cur == r.sink)
    		return true;
    	vector<int> neighbors = r.outgoingNeighbors(cur);
    	for (int neighbor: neighbors) {
    		if (r.edgeCapacity(cur, neighbor) > 0) {
    			s.push(neighbor);
    		}
    	}
    }
    return false;
}
