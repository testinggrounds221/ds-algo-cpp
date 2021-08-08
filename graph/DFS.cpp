#include <iostream>
#include <stack>
using namespace std;

void DFS(int A[][8], int u) {
	static int visited[8]{ 0 };

	if (!visited[u]) {
		cout << u << ", ";
		visited[u] = 1;
		for (int v = 1;v < 8;v++) {
			if (A[u][v] && !visited[v])
				DFS(A, v);
		}
	}
}

void DFS_stack(int A[][8], int u) {
	stack<int> stk;
	int visited[8]{ 0 };
	stk.emplace(u);
	while (!stk.empty()) {
		u = stk.top();
		stk.pop();
		if (!visited[u]) {
			visited[u] = 1;
			cout << u << ", ";
			for (int v = 7;v > 0;v--) {
				if (A[u][v] && !visited[v]) {
					stk.emplace(v);
				}
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
	// cout << "Vertex: 1 -> " << flush;
	// DFS(A, 1);
	cout << "Vertex: 1 Recursive-> " << flush;
	DFS(A, 1);
	// Vertex: 1 Recursive-> 1, 2, 3, 4, 5, 6, 7,
	cout << endl;
	cout << "Vertex: 1 Stack-> " << flush;
	DFS_stack(A, 1);
	// Vertex: 1 Stack-> 1, 4, 5, 7, 6, 3, 2,
	return 0;
}