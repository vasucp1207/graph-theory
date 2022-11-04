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

	bool dfs(int node, vector<bool> &visited, int parent) {
		visited[node] = 1;
		for(auto nbr: l[node]) {
			if(!visited[nbr]) {
				bool nbrFoundCycle = dfs(nbr, visited, node);
				if(nbrFoundCycle) {
					return true;
				}
			}
			else if(nbr != parent) {
				return true;
			}
		}
		return false;
	}

	bool contains_cycle() {
		// assume graph is a single component
		vector<bool> visited(V);
		return dfs(0, visited, 0);
	}
};

int main() {
	
	Graph g(3);
	
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 0);

	cout << g.contains_cycle() << endl;


	
	return 0;
}