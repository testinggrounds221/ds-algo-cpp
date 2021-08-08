#include <iostream>

#define I 32767  // Infinity
#define V 7  // # of vertices in Graph
#define E 9  // # of edges in Graph

using namespace std;

void PrintMCST(int T[][V - 1], int A[][E], int track[]) {
	int sum = 0;
	cout << "\nMinimum Cost Spanning Tree Edges\n" << endl;
	for (int i{ 0 }; i < V - 1; i++) {
		cout << "[" << T[0][i] << "]-----[" << T[1][i] << "]" << endl;
	}
	for (int i = 1;i <= 8;i++) {
		if (track[i] == 2) sum += A[2][i];
	}
	cout << "The Total Weight : " << sum << endl;
}

void Union(int u, int v, int S[]) {
	if (S[u] < S[v]) {
		S[u] += S[v];
		S[v] = u;
	}
	else {
		S[v] += S[u];
		S[u] = v;
	}
}

int Find(int u, int S[]) {
	int x = u; int v = 0;
	while (S[x] > 0) x = S[x];
	while (u != x) { // Making successive search easier
		v = S[u];
		S[u] = x;
		u = v;
	}
	return x;
}

void KruskalsMCST(int A[3][9]) {
	int T[2][V - 1];
	int track[E]{ 0 };
	int set[V + 1] = { -1,-1, -1, -1, -1, -1, -1, -1 };
	int i = 0;
	while (i < V - 1) {
		int min = I;
		int u = 0, v = 0, k = 0;
		for (int j = 0;j < E;j++) {
			if (!track[j] && A[2][j] < min) {
				k = j;
				min = A[2][j];
			}
		}
		u = A[0][k];
		v = A[1][k];
		if (Find(u, set) != Find(v, set)) {
			T[0][i] = u;
			T[1][i] = v;

			Union(Find(u, set), Find(v, set), set);
			track[k] = 2;
			i++;
		}
		else
			track[k] = 1;
	}
	PrintMCST(T, A, track);

}

int main() {
	int edges[3][9] = { { 1, 1,  2,  2, 3,  4,  4,  5,  5},
					   { 2, 6,  3,  7, 4,  5,  7,  6,  7},
					   {25, 5, 12, 10, 8, 16, 14, 20, 18} };

	KruskalsMCST(edges);

	return 0;
}