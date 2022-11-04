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

	int bfs(int source, int dest) {
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
		return dist[dest];
	}
};

int min_dice_throws(int n, vector<pair<int, int>> &snakes, vector<pair<int, int>> &ladders) {

	vector<int> board(n + 1, 0);

	// delta at the curr cell
	for(auto sp: snakes) {
		int s = sp.first;
		int e = sp.second;
		board[s] = e - s;   // -ve delta
	}

	for(auto lp: ladders) {
		int s = lp.first;
		int e = lp.second;
		board[s] = e - s;   // +ve delta
	}

	Graph g(n + 1);
	for(int u = 1; u < n; u++) {
		for(int dice = 1; dice <= 6; dice++) {
			int v = u + dice;
			v += board[v];
			if(v <= n) {
				g.addEdge(u, v);
			}
		}
	}

	return g.bfs(1, n);
}

int main() {

	int n, s, l;
	cin >> n >> s >> l;
	vector<pair<int, int>> snakes;
	vector<pair<int, int>> ladders;
	for(int i = 0; i < s; i++) {
		int st, en;
		cin >> st >> en;
		snakes.push_back({st, en});
	}

	for(int i = 0; i < l; i++) {
		int st, en;
		cin >> st >> en;
		ladders.push_back({st, en});
	}

	cout << min_dice_throws(n, snakes, ladders) << endl;


	
	return 0;
}