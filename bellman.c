/* Relevant questions: PDF Q15/Q44 (Bellman–Ford variants) */
/* Also matches DAOA list items: 15, 44 */
/* Full text: */
/* 15. Implementation of Bellman–Ford algorithm using Dynamic Programming.[^1] */
/* 44. A navigation system needs to find the shortest path between cities in a road network where some road segments may have negative travel costs. Design and implement the Bellman–Ford algorithm using Dynamic Programming to solve this problem.[^1] */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define INF 1000000000

/* Set to 1 to use the hard-coded adjacency matrix below. */
#define USE_MANUAL_MATRIX 1

typedef struct {
	int u;
	int v;
	int w;
} Edge;

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

int main(void)
{
	int V, E, i;
	Edge *e;
	int *dist;
	int src;
	char tok[32];

	e = NULL;
	dist = NULL;

#if USE_MANUAL_MATRIX
	/* Edit this matrix manually. Use -1 for no edge. Diagonal can be 0. */
	V = 5;
	int manual[5][5] = {
		{0, 6, -1, 7, -1},
		{-1, 0, 5, 8, -4},
		{-1, -2, 0, -1, -1},
		{-1, -1, -3, 0, 9},
		{2, -1, 7, -1, 0}
	};

	E = 0;
	for (i = 0; i < V; i++) {
		int j;
		for (j = 0; j < V; j++) {
			if (i != j && manual[i][j] != -1) E++;
		}
	}

	e = (Edge *)malloc((size_t)E * sizeof(Edge));
	if (!e && E > 0) {
		printf("Memory allocation failed.\n");
		return 1;
	}
	int k = 0;
	for (i = 0; i < V; i++) {
		int j;
		for (j = 0; j < V; j++) {
			if (i != j && manual[i][j] != -1) {
				e[k].u = i;
				e[k].v = j;
				e[k].w = manual[i][j];
				k++;
			}
		}
	}
#else
	printf("Enter number of vertices and edges: ");
	if (scanf("%d %d", &V, &E) != 2 || V <= 0 || E < 0) {
		printf("Invalid input.\n");
		return 1;
	}

	e = (Edge *)malloc((size_t)E * sizeof(Edge));
	if (!e && E > 0) {
		printf("Memory allocation failed.\n");
		free(e);
		return 1;
	}

	printf("Enter edges (u v w) with vertices 0..%d (directed):\n", V - 1);
	for (i = 0; i < E; i++) {
		if (scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w) != 3) {
			printf("Invalid edge input.\n");
			free(e);
			return 1;
		}
		if (e[i].u < 0 || e[i].u >= V || e[i].v < 0 || e[i].v >= V) {
			printf("Invalid vertex in edge.\n");
			free(e);
			return 1;
		}
	}
#endif

	dist = (int *)malloc((size_t)V * sizeof(int));
	if (!dist) {
		printf("Memory allocation failed.\n");
		free(e);
		return 1;
	}

	printf("Enter source vertex (%c..%c or 0..%d): ", (V <= 26 ? 'A' : '0'), (V <= 26 ? (char)('A' + (V - 1)) : '0'), V - 1);
	if (scanf("%31s", tok) != 1 || (src = parseVertexToken(tok, V)) == -1) {
		printf("Invalid source.\n");
		free(e);
		free(dist);
		return 1;
	}

	for (i = 0; i < V; i++) dist[i] = INF;
	dist[src] = 0;

	for (i = 1; i <= V - 1; i++) {
		int changed = 0;
		int j;
		for (j = 0; j < E; j++) {
			int u = e[j].u, v = e[j].v, w = e[j].w;
			if (dist[u] < INF && dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				changed = 1;
			}
		}
		if (!changed) break;
	}

	for (i = 0; i < E; i++) {
		int u = e[i].u, v = e[i].v, w = e[i].w;
		if (dist[u] < INF && dist[u] + w < dist[v]) {
			printf("Negative weight cycle detected. Shortest paths not well-defined.\n");
			free(e);
			free(dist);
			return 0;
		}
	}

	printf("\nShortest distances from ");
	printV(src, V);
	printf(":\n");
	for (i = 0; i < V; i++) {
		printV(src, V);
		printf(" -> ");
		printV(i, V);
		if (dist[i] >= INF) printf(" : INF\n");
		else printf(" : %d\n", dist[i]);
	}

	free(e);
	free(dist);
	return 0;
}

/*
Complexity & classification:
- Problem type: shortest path (single-source, handles negative weights)
- Class: P (polynomial-time)
- Time: O(VE)
- Space: O(V + E)
- Notes: Detects negative-weight cycles reachable from the source.
*/
