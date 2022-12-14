#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
using namespace std;

class Graph {

	int V;
	list<int> *l;
	
public:
	Graph(int v) {
		V = v;
		l = new list<int>[V];
	}
	
	void addEdge(int x, int y, bool undir = true) {
		l[x].push_back(y);
		if(undir) {
			l[y].push_back(x);
		}
	}
	
	void printAdjList() {
		for(int i = 0; i < V; i++) {
			cout << i << "-> ";
			for(auto node: l[i]) {
				cout << node << " ";
			} cout << endl;
		}
	}
};

int main() {
	
	Graph g(6);
	g.addEdge(0,1);
	g.addEdge(0,4);
	g.addEdge(2,1);
	g.addEdge(3,4);
	g.addEdge(4,5);
	g.addEdge(2,3);
	g.addEdge(3,5);
	g.printAdjList();
	
	return 0;
}