#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

// MST Set = []
// Active Edge = edge from a vertex in MST set to V
// MST Edge = an edge that has been included in MST so far

class Graph {
	int V;
	vector<pair<int, int> > *l;

public:
	Graph(int v) {
		V = v;
		l = new vector<pair<int, int> >[v];
	}

	void addEdge(int x, int y, int w) {
		l[x].push_back({y, w});
		l[y].push_back({x, w});
	}

	int prim_mst() {
		priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
		bool *visited = new bool[V];
		int ans = 0;

		// begin 
		q.push({0, 0});  // weight, node

		while(q.empty() == false) {
			// pick out the edge with the min weight
			auto best = q.top();
			q.pop();

			int to = best.second;
			int weight = best.first;

			if(visited[to]) {
				// discard the edge
				continue;
			}

			// otherwise, take the curr edge
			ans += weight;
			visited[to] = 1;

			// add the edges in the queue
			for(auto x: l[to]) {
				if(visited[x.first] == 0) {
					q.push({x.second, x.first});
				}
			}
		}

		return ans;
	}
};

int main() {

	int n, m;
	cin >> n >> m;
	Graph g(n);
	for(int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g.addEdge(u, v, w);
	}

	cout << g.prim_mst() << endl;



	return 0;
}