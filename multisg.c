/* Relevant questions: PDF Q28 (Multistage Graph) */
/* Also matches DAOA list items: 28 */
/* Full text: */
/* 28. A tourist plans to visit several locations in a specific order, and each stage of the journey offers multiple possible routes with different travel costs. Using the Multistage Graph Dynamic Programming approach, determine the minimum-cost path the tourist should follow to complete the trip in the required sequence.[^1] */

#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000

/* Set to 1 to use the hard-coded adjacency matrix below. */
#define USE_MANUAL_MATRIX 1

static void printV(int v, int n)
{
	if (n <= 26) printf("%c", (char)('A' + v));
	else printf("%d", v);
}

int main(void)
{
	int n, i, j;
	int **c;
	int *cost;
	int *nxt;
	int src, sink;

#if USE_MANUAL_MATRIX
	/* Edit this matrix manually. Use -1 for no edge. */
	/* NOTE: Vertices should be in stage/topological order for multistage DP. */
	n = 8;
	src = 0;
	sink = 7;
	int manual[8][8] = {
		{-1, 1, 2, 5, -1, -1, -1, -1},
		{-1, -1, -1, -1, 4, 11, -1, -1},
		{-1, -1, -1, -1, 9, 5, 16, -1},
		{-1, -1, -1, -1, -1, -1, 2, -1},
		{-1, -1, -1, -1, -1, -1, -1, 18},
		{-1, -1, -1, -1, -1, -1, -1, 13},
		{-1, -1, -1, -1, -1, -1, -1, 2},
		{-1, -1, -1, -1, -1, -1, -1, -1}
	};
#else

	printf("Enter number of vertices: ");
	if (scanf("%d", &n) != 1 || n <= 1) {
		printf("Invalid n.\n");
		return 1;
	}
	printf("Enter source and sink vertices (0..%d): ", n - 1);
	if (scanf("%d %d", &src, &sink) != 2 || src < 0 || sink < 0 || src >= n || sink >= n) {
		printf("Invalid source/sink.\n");
		return 1;
	}
#endif

	c = (int **)malloc((size_t)n * sizeof(int *));
	cost = (int *)malloc((size_t)n * sizeof(int));
	nxt = (int *)malloc((size_t)n * sizeof(int));
	if (!c || !cost || !nxt) {
		printf("Memory allocation failed.\n");
		free(c);
		free(cost);
		free(nxt);
		return 1;
	}
	for (i = 0; i < n; i++) {
		c[i] = (int *)malloc((size_t)n * sizeof(int));
		if (!c[i]) {
			printf("Memory allocation failed.\n");
			for (j = 0; j < i; j++) free(c[j]);
			free(c);
			free(cost);
			free(nxt);
			return 1;
		}
	}

	printf("Enter cost adjacency matrix (use -1 for no edge).\n");
	printf("Note: For multistage DP, vertices should be in stage/topological order.\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			int x;
#if USE_MANUAL_MATRIX
			x = manual[i][j];
#else
			if (scanf("%d", &x) != 1) {
				printf("Invalid input.\n");
				for (i = 0; i < n; i++) free(c[i]);
				free(c);
				free(cost);
				free(nxt);
				return 1;
			}
#endif
			c[i][j] = x;
		}
	}

	for (i = 0; i < n; i++) {
		cost[i] = INF;
		nxt[i] = -1;
	}
	cost[sink] = 0;

	for (i = n - 1; i >= 0; i--) {
		if (i == sink) continue;
		for (j = 0; j < n; j++) {
			if (c[i][j] >= 0 && cost[j] < INF && c[i][j] + cost[j] < cost[i]) {
				cost[i] = c[i][j] + cost[j];
				nxt[i] = j;
			}
		}
	}

	if (cost[src] >= INF || nxt[src] == -1) {
		printf("No path found from %d to %d.\n", src, sink);
	} else {
		printf("Minimum cost from ");
		printV(src, n);
		printf(" to ");
		printV(sink, n);
		printf(" = %d\n", cost[src]);
		printf("Path: ");
		printV(src, n);
		printf(" ");
		int u = src;
		while (u != sink && u != -1) {
			u = nxt[u];
			if (u == -1) break;
			printf("-> ");
			printV(u, n);
			printf(" ");
		}
		printf("\n");
	}

	for (i = 0; i < n; i++) free(c[i]);
	free(c);
	free(cost);
	free(nxt);
	return 0;
}

/*
Complexity & classification:
- Problem type: shortest path in a multistage graph (DAG DP)
- Class: P (polynomial-time)
- Time: O(V^2) as written (matrix scan); on adjacency lists it’s O(E)
- Space: O(V^2) for matrix + O(V) for cost/next
- Notes: Requires vertices in stage/topological order for the simple backward DP.
*/
