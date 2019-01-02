#include <iostream>
#include <string>

#include "adjacency_list.h"

using namespace std;

bool containsEdge(Graph const * const g, int src, int dest) {
	for (int i = 0; i < g->n; i++) {
		if (g->adjLists[i].vertex == src) {
			LinkedListNode * temp = g->adjLists[i].edges;
			while (temp != NULL) {
				if (temp->v == dest) return true;
				temp = temp->next;
			}
			break;
		}
	}
	return false;
}

void addEdge(Graph* g, int src, int dest) {
	if (containsEdge(g, src, dest)) return;
    for (int i = 0; i < g->n; i++) {
    	if (g->adjLists[i].vertex == src) {
    		LinkedListNode * newhead = new LinkedListNode();
    		newhead->v = dest;
    		newhead->next = g->adjLists[i].edges;
    		g->adjLists[i].edges = newhead;
    		break;
    	}
    }
}

int numOutgoingEdges(Graph const * const g, int v) {
    for (int i = 0; i < g->n; i++) {
    	if (g->adjLists[i].vertex == v) {
    		int counter = 0;
    		LinkedListNode * temp = g->adjLists[i].edges;
    		while (temp != NULL) {
    			counter++;
    			temp = temp->next;
    		}
    		return counter;
    	}
    }
    return 0;
}


int numIncomingEdges(Graph const * const g, int v) {
    int count = 0;
    for (int i = 0; i < g->n; i++) {
    	LinkedListNode * temp = g->adjLists[i].edges;
    	while (temp != NULL) {
    		if (temp->v == v) count++;
    		temp = temp->next;
    	}
    }
    return count;
}

// No need to modify the functions below

Graph* createVertices(int numV) {
        Graph* g = new Graph();
        g->adjLists = new AdjacencyList[numV];
        g->n = numV;

        // Initialize the vertices
        for (int i = 0; i < numV; i += 1) {
                g->adjLists[i].vertex = i;
                g->adjLists[i].edges = NULL;
        }

        return g;
}

void printGraph(Graph const * const g) {
    for (int i = 0; i < g->n; i += 1) {
        AdjacencyList adjList = g->adjLists[i];

        int v = adjList.vertex;
        // Vertex
        cout << "Vertex: " << v << endl;

        // Print number of incoming and outgoing edges
        int inc = numIncomingEdges(g, v);
        int out = numOutgoingEdges(g, v);
        cout << "Number of incoming edges: " << inc << endl;
        cout << "Number of outgoing edges: " << out << endl;

        cout << "\n" << endl;
    }
}
