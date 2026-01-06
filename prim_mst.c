/* Relevant questions: PDF Q18/Q29/Q30 (Prim’s MST variants) */
/* Also matches DAOA list items: 18, 29, 30 */
/* Full text: */
/* 18. Implementation of Prim’s algorithm using greedy approach.[^1] */
/* 29. A housing society requires an electricity distribution network connecting all houses with the minimum total wiring cost. Implement Prim’s algorithm to design a minimum spanning tree that determines the optimal connections between houses to distribute electricity efficiently.[^1] */
/* 30. A university campus plans to set up an internet backbone connecting all its buildings. Each possible connection between buildings has a specific installation cost. Apply Prim’s algorithm to design a minimum-cost network that connects all campus buildings efficiently.[^1] */

#include <stdio.h>
#include <stdlib.h>

/* Set to 1 to use the hard-coded adjacency matrix below. */
#define USE_MANUAL_MATRIX 0

static void printV(int v, int n)
{
	if (n <= 26) printf("%c", (char)('A' + v));
	else printf("%d", v);
}

#define INF 1000000000

static int minKey(int key[], int inMST[], int n)
{
	int i, u = -1;
	for (i = 0; i < n; i++) {
		if (!inMST[i] && (u == -1 || key[i] < key[u])) u = i;
	}
	return u;
}

int main(void)
{
	int n, i, j;
	int **w;
	int *key, *parent, *inMST;
	int total = 0;

#if USE_MANUAL_MATRIX
	/* Edit this matrix manually. Use 0 for no edge. Diagonal can be 0. */
	n = 5;
	int manual[5][5] = {
		{0, 2, 0, 6, 0},
		{2, 0, 3, 8, 5},
		{0, 3, 0, 0, 7},
		{6, 8, 0, 0, 9},
		{0, 5, 7, 9, 0}
	};
#else

	printf("Enter number of vertices: ");
	if (scanf("%d", &n) != 1 || n <= 0) {
		printf("Invalid n.\n");
		return 1;
	}
#endif

	w = (int **)malloc((size_t)n * sizeof(int *));
	key = (int *)malloc((size_t)n * sizeof(int));
	parent = (int *)malloc((size_t)n * sizeof(int));
	inMST = (int *)malloc((size_t)n * sizeof(int));
	if (!w || !key || !parent || !inMST) {
		printf("Memory allocation failed.\n");
		free(w);
		free(key);
		free(parent);
		free(inMST);
		return 1;
	}
	for (i = 0; i < n; i++) {
		w[i] = (int *)malloc((size_t)n * sizeof(int));
		if (!w[i]) {
			printf("Memory allocation failed.\n");
			for (j = 0; j < i; j++) free(w[j]);
			free(w);
			free(key);
			free(parent);
			free(inMST);
			return 1;
		}
	}

	printf("Enter adjacency matrix weights (use 0 for no edge; diagonal can be 0):\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			int x;
#if USE_MANUAL_MATRIX
			x = manual[i][j];
#else
			if (scanf("%d", &x) != 1) {
				printf("Invalid input.\n");
				for (i = 0; i < n; i++) free(w[i]);
				free(w);
				free(key);
				free(parent);
				free(inMST);
				return 1;
			}
#endif
			w[i][j] = x;
		}
	}

	for (i = 0; i < n; i++) {
		key[i] = INF;
		parent[i] = -1;
		inMST[i] = 0;
	}
	key[0] = 0;

	for (i = 0; i < n; i++) {
		int u = minKey(key, inMST, n);
		if (u == -1 || key[u] == INF) break;
		inMST[u] = 1;
		for (j = 0; j < n; j++) {
			if (!inMST[j] && w[u][j] > 0 && w[u][j] < key[j]) {
				key[j] = w[u][j];
				parent[j] = u;
			}
		}
	}

	printf("\nMST edges (u - v : weight):\n");
	for (i = 1; i < n; i++) {
		if (parent[i] == -1) {
			printf("Graph is disconnected; MST not possible for all vertices.\n");
			break;
		}
		printV(parent[i], n);
		printf(" - ");
		printV(i, n);
		printf(" : %d\n", w[parent[i]][i]);
		total += w[parent[i]][i];
	}
	if (i == n) printf("Total weight = %d\n", total);

	for (i = 0; i < n; i++) free(w[i]);
	free(w);
	free(key);
	free(parent);
	free(inMST);
	return 0;
}

/*
Complexity & classification:
- Problem type: minimum spanning tree (greedy)
- Class: P (polynomial-time)
- Time: O(V^2) as written (adjacency matrix + linear min-key selection)
- Space: O(V^2) for matrix + O(V) arrays
- Notes: With a min-heap + adjacency list, typical bound is O(E log V).
*/
