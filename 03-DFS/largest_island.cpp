#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
#include<queue>
using namespace std;

int dfs(vector<vector<int> > &matrix, vector<vector<bool> > &visited, int i, int j, int m, int n) {

	visited[i][j] = 1;
	int cs = 1;

	// 4 way dfs
	int dx[] = {1, -1, 0, 0};
	int dy[] = {0, 0, 1, -1};

	for(int k = 0; k < 4; k++) {
		int nx = i + dx[k];
		int ny = j + dy[k];

		if(nx >= 0 && ny >= 0 and nx < m && ny < n && matrix[nx][ny] and !visited[nx][ny]) {
			int sub = dfs(matrix, visited, nx, ny, m, n);
			cs += sub;
		}
	}

	return cs;
}

int largest_island(vector<vector<int> > &matrix) {
	int m = matrix.size();
	int n = matrix[0].size();

	vector<vector<bool> > visited(m, vector<bool>(n, false));

	int largest = 0;
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if(!visited[i][j] && matrix[i][j]) {
				// size of island conaining the current cell
				int size = dfs(matrix, visited, i, j, m, n);
				if(size > largest) {
					largest = size;
				}
			}
		}
	}
	return largest;
}

int main() {
	
	vector<vector<int> > grid = {
		{1, 0, 0, 1, 0},
		{1, 0, 1, 0, 0},
		{0, 0, 1, 0, 1},
		{1, 0, 1, 1, 1},
		{1, 0, 1, 1, 0}
	};

	cout << largest_island(grid) << endl;


	
	return 0;
}