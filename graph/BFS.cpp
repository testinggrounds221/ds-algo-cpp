#include <iostream>
#include <queue>
using namespace std;

void BFS(int A[][8], int u) {
	queue<int> q;
	int visited[8]{ 0 };

	visited[u] = 1;
	cout << u << ", ";
	q.emplace(u);

	while (!q.empty()) {
		u = q.front();
		q.pop();
		for (int v = 1;v <= 8;v++) {
			if (A[u][v] && !visited[v]) {
				visited[v] = 1;
				cout << v << ", ";
				q.emplace(v);

			}
		}
	}

}

int main() {
	int A[8][8] = { {0, 0, 0, 0, 0, 0, 0, 0},
				   {0, 0, 1, 1, 1, 0, 0, 0},
				   {0, 1, 0, 1, 0, 0, 0, 0},
				   {0, 1, 1, 0, 1, 1, 0, 0},
				   {0, 1, 0, 1, 0, 1, 0, 0},
				   {0, 0, 0, 1, 1, 0, 1, 1},
				   {0, 0, 0, 0, 0, 1, 0, 0},
				   {0, 0, 0, 0, 0, 1, 0, 0} };
	cout << "Vertex: 1 -> " << flush;
	BFS(A, 1);
	cout << "Vertex: 4 -> " << flush;
	BFS(A, 4);
	return 0;
}
