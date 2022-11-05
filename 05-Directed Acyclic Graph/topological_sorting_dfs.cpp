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
	
	void addEdge(int i, int j, bool undir = false) {
		l[i].push_back(j);
		if(undir) {
			l[j].push_back(i);
		}
	}

	void dfs(int node, vector<bool> &visited, list<int> &ordering) {
		visited[node] = true;

		for(int nbr: l[node]) {
			if(!visited[nbr]) {
				dfs(nbr, visited, ordering);
			}
		}

		// push the node when we going back from this
		ordering.push_front(node);
		return ;
	}

	void dfs_topological_sort() {
		vector<bool> visited(V);
		list<int> ordering;

		for(int i = 0; i < V; i++) {
			if(!visited[i]) {
				dfs(i, visited, ordering);
			}
		}

		for(auto node: ordering) {
			cout << node << " ";
		} cout << endl;
	}
};

int main() {
	
	Graph g(5);
	
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(0, 3);
	g.addEdge(0, 4);
	g.addEdge(3, 4);

	g.dfs_topological_sort();


	
	return 0;
}