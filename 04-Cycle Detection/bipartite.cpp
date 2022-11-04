#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
#include<queue>
using namespace std;

bool dfsHelper(vector<int> graph[], int node, vector<int> &visited, int parent, int color) {
	visited[node] = color;

	for(auto nbr: graph[node]) {
		if(visited[nbr] == 0) {
			int sub = dfsHelper(graph, nbr, visited, node, 3 - color);
			if(sub == false) return false;
		}
		else if(nbr != parent && color == visited[nbr]) {
			return false;
		}
	}
	return true;
}

bool dfs(vector<int> graph[], int n) {
	vector<int> visited(n);

	bool ans = dfsHelper(graph, 0, visited, -1, 1);
	return ans;
}

int main() {
	
	int n, m;
	cin >> n >> m;
	vector<int> graph[n];
	while(m--) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	// color the nodes(curr = 1, nbr = 2)
	cout << dfs(graph, n);



	
	return 0;
}