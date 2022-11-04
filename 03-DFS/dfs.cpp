#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph {

	int V;
	list<int> *l;

public:
	Graph(int v) {
		V = v;
		l = new list<int>[V];
	}
	
	void addEdge(int i, int j, bool undir = true) {
		l[i].push_back(j);
		if(undir) {
			l[j].push_back(i);
		}
	}

	void dfsHelper(int node, bool *visited) {
		visited[node] = 1;
		cout << node << " ";

		// dfs call on unvisitd node
		for(int nbr: l[node]) {
			if(!visited[nbr]) {
				dfsHelper(nbr, visited);
			}
		}
	}

	void dfs(int source) {
		bool *visited = new bool[V];
		dfsHelper(source, visited);
	}
};

int main() {
	
	Graph g(7);
	
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 5);
	g.addEdge(5, 6);
	g.addEdge(4, 5);
	g.addEdge(0, 4);
	g.addEdge(3, 4);

	g.dfs(0);


	
	return 0;
}