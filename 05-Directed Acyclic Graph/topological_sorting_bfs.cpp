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

	void topological_sort() {
		vector<int> indegre(V);

		for(int i = 0; i < V; i++) {
			for(auto nbr: l[i]) {
				indegre[nbr]++;
			}
		}

		queue<int> q;
		for(int i = 0; i < V; i++) {
			if(indegre[i] == 0) {
				q.push(i);
			}
		}

		while(!q.empty()) {
			int node = q.front();
			cout << node << " ";
			q.pop();

			for(auto nbr: l[node]) {
				indegre[nbr]--;
				if(indegre[nbr] == 0) {
					q.push(nbr);
				}
			}
		}
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

	g.topological_sort();


	
	return 0;
}