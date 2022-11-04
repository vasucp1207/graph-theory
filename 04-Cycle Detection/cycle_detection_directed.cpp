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

	bool dfs(int node, vector<bool> &visited, vector<bool> &stack) {

		visited[node] = 1;
		stack[node] = 1;

		for(int nbr: l[node]) {
			// backedge
			if(stack[nbr]) {
				return true;
			}
			else if(visited[nbr] == false) {
				bool nbrFoundCycle = dfs(nbr, visited, stack);
				if(nbrFoundCycle) {
					return true;
				}
			}
		}
		stack[node] = false;
		return false;
	}

	bool contains_cycle() {
		vector<bool> visited(V, false);
		vector<bool> stack(V, false);

		for(int i = 0; i < V; i++) {
			if(!visited[i]) {
				if(dfs(i, visited, stack)) {
					return true;
				}
			}
		}
		return false;
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