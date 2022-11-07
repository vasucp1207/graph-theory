#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

// cycle detection in undirected graph using dsu
class Graph {
	int V;
	list<pair<int, int> > l;

public:
	Graph(int v) {
		V = v;
	}

	void addEdge(int u, int v) {
		l.push_back({u, v});
	}

	int findSet(int i, int parent[]) {
		if(parent[i] == -1) {
			return i;
		}
		// path compression
		return parent[i] = findSet(parent[i], parent);
	}

	void union_set(int x, int y, int parent[], int rank[]) {
		int s1 = findSet(x, parent);
		int s2 = findSet(y, parent);

		if(s1 != s2) {
			if(rank[s1] < rank[s2])
				swap(s1, s2);
			// merge smaller tree into the bigger one
			parent[s2] = s1;
			// increase the depth of tree by one if both have equal depth
			if (rank[s1] == rank[s2])
            	rank[s1]++;
		}
	}

	bool contains_cycle() {
		// dsu logic
		int *parent = new int[V + 1];
		int *rank = new int[V + 1];
		for(int i = 0; i < V; i++) {
			parent[i] = -1;
			rank[i] = 1;
		}

		for(auto edge: l) {
			int i = edge.first;
			int j = edge.second;

			int s1 = findSet(i, parent);
			int s2 = findSet(j, parent);

			if(s1 != s2) {
				union_set(s1, s2, parent, rank);
			} else {
				return true;
			}
		}

		delete [] parent;
		return false;
	}
};

int main() {

	Graph g(4);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 1);

	cout << g.contains_cycle() << endl;


	return 0;
}