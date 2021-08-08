#include <iostream>
#define V 8
#define I 32767

using namespace std;

void PrintMST(int T[][V - 2], int G[V][V]) {
	cout << "\nMinimum Spanning Tree Edges (w/ cost)\n" << endl;
	int sum{ 0 };
	for (int i{ 0 }; i < V - 2; i++) {
		int c = G[T[0][i]][T[1][i]];
		cout << "[" << T[0][i] << "]---[" << T[1][i] << "] cost: " << c << endl;
		sum += c;
	}
	cout << endl;
	cout << "Total cost of MST: " << sum << endl;
}


void PrimsMST(int cost[][V], int n) {
	int min = I;
	int track[V];
	int T[2][V - 2]{ 0 };
	int u, v;
	for (int i = 1; i < V;i++) {
		track[i] = I;
		for (int j = i; j <= V;j++) {
			if (cost[i][j] < min) {
				u = i;
				v = j;
				min = cost[i][j];
			}
		}
	}
	T[0][0] = u;
	T[1][0] = v;
	track[u] = track[v] = 0;

	for (int i = 1;i < V;i++) {
		if (track[i]) {
			if (cost[i][u] < cost[i][v])
				track[i] = u;
			else
				track[i] = v;
		}
	}

	for (int i = 1;i < n - 1;i++) {
		int k;
		min = I;
		for (int j = 1;j < V;j++) {
			if (track[j] != 0 && cost[j][track[j]] < min) {
				k = j;
				min = cost[j][track[j]];
			}
		}
		T[0][i] = k;
		T[1][i] = track[k];
		track[k] = 0;

		// Update track array to track min cost edges
		for (int j{ 1 }; j < V; j++) {
			if (track[j] != 0 && cost[j][k] < cost[j][track[j]]) {
				track[j] = k;
			}
		}
	}
	PrintMST(T, cost);
}


int main() {

	int cost[V][V]{
			{I, I, I, I, I, I, I, I},
			{I, I, 25, I, I, I, 5, I},
			{I, 25, I, 12, I, I, I, 10},
			{I, I, 12, I, 8, I, I, I},
			{I, I, I, 8, I, 16, I, 14},
			{I, I, I, I, 16, I, 20, 18},
			{I, 5, I, I, I, 20, I, I},
			{I, I, 10, I, 14, 18, I, I},
	};

	int n = sizeof(cost[0]) / sizeof(cost[0][0]) - 1;

	PrimsMST(cost, n);

	return 0;
}