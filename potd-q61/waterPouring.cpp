#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

#define EMPTY 0

class Node {
    public:
        int a;
        int b;
        vector<Node *> neighbors;
        Node () : a(EMPTY), b(EMPTY), neighbors() {}
        Node (const int &a_, const int &b_) : a(a_), b(b_), neighbors() {}
        Node (const int &a_, const int &b_, const vector<Node *> &neighbors_) : a(a_), b(b_), neighbors(neighbors_) {}
        Node (const Node &tmpNode) : a(tmpNode.a), b(tmpNode.b), neighbors() {}
        bool operator==(const Node & b_node)
        {
            return a == b_node.a && b == b_node.b;
        }
        Node &operator=(const Node & b_node) {
            // WARNING: This operator does not copy the vector
            a = b_node.a;
            b = b_node.b;
            return *this;
        }
};

struct Graph {
    vector<Node *> nodes;
};


Graph createGraph(int capacity_a, int capacity_b) {
    Graph g;
    // Add all states
    for (int a = 0; a <= capacity_a; a++) {
    	for (int b = 0; b <= capacity_b; b++) {
    		Node * cur_node = new Node(a, b);
    		g.nodes.push_back(cur_node);
    	}
    }
    // Add edges if they belong according to rules
    for (Node * cur_node1: g.nodes) {
    	for (Node * cur_node2: g.nodes) {
			// If this is true, then an edge should be added from 1 to 2
    		bool addEdge = false;
    		// Empty either a or b
    		if (0 == cur_node2->a && cur_node1->b == cur_node2->b) addEdge = true;
    		if (cur_node1->a == cur_node2->a && 0 == cur_node2->b) addEdge = true;
    		// Fill either a or b
    		if (capacity_a == cur_node2->a && cur_node1->b == cur_node2->b) addEdge = true;
    		if (cur_node1->a == cur_node2->a && capacity_b == cur_node2->b) addEdge = true;
    		// Pour from a to b
    		int total = cur_node1->a + cur_node1->b;
    		int amounta = 0;
    		int amountb = 0;
    		while (total > 0) {
    			if (amountb != capacity_b) amountb++;
    			else amounta++;
    			total--;
    		}
    		if (amounta == cur_node2->a && amountb == cur_node2->b) addEdge = true;
    		// Pour from b to a
    		total = cur_node1->a + cur_node1->b;
    		amounta = 0;
    		amountb = 0;
    		while (total > 0) {
    			if (amounta != capacity_a) amounta++;
    			else amountb++;
    			total--;
    		}
    		if (amounta == cur_node2->a && amountb == cur_node2->b) addEdge = true;

    		if (addEdge) cur_node1->neighbors.push_back(cur_node2);
    	}
    }
    return g;
}

int findSolution(Graph g, int target) {
	if (g.nodes.size() == 0) return -1;

	queue<Node *> q;
	queue<int> stepq;
	q.push(g.nodes[0]);
	stepq.push(0);

	unordered_map<Node *, bool> visited;
	for (Node * nodey: g.nodes) {
		visited[nodey] = false;
	}

	Node * cur_node;
	int cur_step;
	while (!q.empty()) {
		cur_node = q.front();
		cur_step = stepq.front();
		q.pop();
		stepq.pop();
		visited[cur_node] = true;
		// check if state matches criteria
		if (cur_node->a == target || cur_node->b == target) return cur_step;
		// If not, then traverse neighbor nodes
		for (Node * new_node: cur_node->neighbors) {
			if (!visited[new_node]) {
				q.push(new_node);
				stepq.push(cur_step + 1);
			}
		}
	}
	return -1;
}

int waterPouring(int a, int b, int target) {
    // Call createGraph
    // Call findSolution
    Graph stateMachineGraph = createGraph(a, b);
    int steps = findSolution(stateMachineGraph, target);
    for (Node *graphNode : stateMachineGraph.nodes)
        {
            delete graphNode;
        }
    return steps;
}
