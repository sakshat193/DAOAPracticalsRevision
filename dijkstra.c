/* Relevant questions: PDF Q5 (Dijkstra’s Algorithm) */
/* Also matches DAOA list items: 5 */
/* Full text: */
/* 5. Implement Dijkstra’s algorithm to find the single source shortest path.[^1] */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define INF 1000000000

/* Set to 1 to use the hard-coded adjacency matrix below. */
#define USE_MANUAL_MATRIX 1

static void printV(int v, int n)
{
	if (n <= 26) printf("%c", (char)('A' + v));
	else printf("%d", v);
}

static int parseVertexToken(const char *tok, int n)
{
	if (!tok || !tok[0]) return -1;
	if (n <= 26 && strlen(tok) == 1 && isalpha((unsigned char)tok[0])) {
		char c = (char)toupper((unsigned char)tok[0]);
		int idx = (int)(c - 'A');
		if (0 <= idx && idx < n) return idx;
	}
	{
		char *end = NULL;
		long v = strtol(tok, &end, 10);
		if (end && *end == '\0' && 0 <= v && v < n) return (int)v;
	}
	return -1;
}

static int minVertex(int dist[], int vis[], int n)
{
	int i, u = -1;
	for (i = 0; i < n; i++) {
		if (!vis[i] && (u == -1 || dist[i] < dist[u])) u = i;
	}
	return u;
}

int main(void)
{
	int n, i, j, src;
	int **w;
	int *dist, *vis;
	char tok[32];

#if USE_MANUAL_MATRIX
	/* Edit this matrix manually. Use -1 for no edge. Diagonal can be 0. */
	n = 5;
	int manual[5][5] = {
		{0, 10, 3, -1, -1},
		{-1, 0, 1, 2, -1},
		{-1, 4, 0, 8, 2},
		{-1, -1, -1, 0, 7},
		{-1, -1, -1, 9, 0}
	};
#else

	printf("Enter number of vertices: ");
	if (scanf("%d", &n) != 1 || n <= 0) {
		printf("Invalid n.\n");
		return 1;
	}
#endif

	w = (int **)malloc((size_t)n * sizeof(int *));
	dist = (int *)malloc((size_t)n * sizeof(int));
	vis = (int *)malloc((size_t)n * sizeof(int));
	if (!w || !dist || !vis) {
		printf("Memory allocation failed.\n");
		free(w);
		free(dist);
		free(vis);
		return 1;
	}
	for (i = 0; i < n; i++) {
		w[i] = (int *)malloc((size_t)n * sizeof(int));
		if (!w[i]) {
			printf("Memory allocation failed.\n");
			for (j = 0; j < i; j++) free(w[j]);
			free(w);
			free(dist);
			free(vis);
			return 1;
		}
	}

	printf("Enter adjacency matrix weights (use -1 for no edge):\n");
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
				free(dist);
				free(vis);
				return 1;
			}
#endif
			w[i][j] = x;
		}
	}

	printf("Enter source vertex (%c..%c or 0..%d): ", (n <= 26 ? 'A' : '0'), (n <= 26 ? (char)('A' + (n - 1)) : '0'), n - 1);
	if (scanf("%31s", tok) != 1 || (src = parseVertexToken(tok, n)) == -1) {
		printf("Invalid source.\n");
		for (i = 0; i < n; i++) free(w[i]);
		free(w);
		free(dist);
		free(vis);
		return 1;
	}

	for (i = 0; i < n; i++) {
		dist[i] = INF;
		vis[i] = 0;
	}
	dist[src] = 0;

	for (i = 0; i < n; i++) {
		int u = minVertex(dist, vis, n);
		if (u == -1 || dist[u] == INF) break;
		vis[u] = 1;
		for (j = 0; j < n; j++) {
			if (!vis[j] && w[u][j] >= 0 && dist[u] + w[u][j] < dist[j]) {
				dist[j] = dist[u] + w[u][j];
			}
		}
	}

	printf("\nShortest distances from ");
	printV(src, n);
	printf(":\n");
	for (i = 0; i < n; i++) {
		printV(src, n);
		printf(" -> ");
		printV(i, n);
		if (dist[i] >= INF) printf(" : INF\n");
		else printf(" : %d\n", dist[i]);
	}

	for (i = 0; i < n; i++) free(w[i]);
	free(w);
	free(dist);
	free(vis);
	return 0;
}

/*
Complexity & classification:
- Problem type: shortest path (single-source, non-negative weights)
- Class: P (polynomial-time)
- Time: O(V^2) as written (adjacency matrix + linear min selection)
- Space: O(V^2) for matrix + O(V) for arrays
- Notes: With a priority queue + adjacency list, typical bound is O((V+E) log V).
*/
