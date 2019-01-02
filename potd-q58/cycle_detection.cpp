#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>

#include "graph.cpp"

using namespace std;



bool hasCycles(Graph const & g) {
	
	int v = g.nodes.size();

	unordered_map<int, bool> visited_vertex;
	unordered_map<string, bool> visited_edge;
	for (auto node1: g.nodes) {
    	visited_vertex[node1->value] = false;
    	for (auto node2: g.nodes) {
    		string edge = to_string(node1->value) + "-" + to_string(node2->value);
    		visited_edge[edge] = false;
    	}
    }

	for (int i = v - 1; i >= 0; i--) {
		Node node = *(g.nodes[i]);
		int cur_val = node.value;
		stack<Node> s;
		s.push(node);

		for (auto vertex: visited_vertex)
			vertex.second = false;
		for (auto edge: visited_edge)
			edge.second = false;

		while (!s.empty()) {
    		Node v = s.top();
    		s.pop();
    		for (auto node1: v.outgoingNeighbors) {
    			string edge = to_string(v.value) + "-" + to_string(node1->value);
    			if (!visited_vertex[node1->value]) {
    				visited_vertex[node1->value] = true;
    				visited_edge[edge] = true;
   					s.push(*node1);
    			}
    			else if (!visited_edge[edge]) visited_edge[edge] = true;
    			if (node1->value == cur_val) return true;
   			}
    	}
	}
	return false;
}
