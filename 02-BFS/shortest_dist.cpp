#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
#include<queue>
using namespace std;

// for unweighted and undirected graph
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

	void bfs(int source, int dest) {
		queue<int> q;
		q.push(source);
		bool *visited = new bool[V];
		visited[source] = 1;

		// dist and parent
		int *dist = new int[V];
		int *parent = new int[V];

		parent[source] = source;
		dist[source] = 0;

		while(!q.empty()) {
			int f = q.front();
			q.pop();

			for(auto nbr: l[f]) {
				if(!visited[nbr]) {
					q.push(nbr);
					visited[nbr] = 1;
					// parent and dist
					parent[nbr] = f;
					dist[nbr] = dist[f] + 1;
				}
			}
		}

		// shortest dist to all node from source
		for(int i = 0; i < V; i++) {
			cout << dist[i] << " ";
		} cout << endl;

		// print the path from source to any dest
		int temp = dest;
		while(temp != source) {
			cout << temp << " ";
			temp = parent[temp];
		}
		cout << source << endl;
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

	g.bfs(1, 6);


	
	return 0;
}