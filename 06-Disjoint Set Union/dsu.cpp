#include<iostream>
#include<vector>
using namespace std;

vector<int> parent;
void make_set(int v) {
	parent[v] = v;
}

int find_set(int v) {
	if(parent[v] == v)
		return v;

	else return find_set(parent[v]);
}

void union_set(int a, int b) {
	a = find_set(a);
	b = find_set(b);

	if(a != b) {
		parent[b] = a;
	}
}

int main() {

	parent.assign(7, 0);
	for(int i = 1; i <= 6; i++) {
		make_set(i);
	}

	union_set(2, 1);
	union_set(3, 1);
	union_set(4, 1);
	union_set(5, 1);
	union_set(6, 1);

	for(int i = 1; i <= 6; i++) {
		cout << parent[i] << " ";
	}

	return 0;
}