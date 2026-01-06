/* Relevant questions: PDF Q17/Q31 (Kruskal’s MST variants) */
/* Also matches DAOA list items: 17, 31 */
/* Full text: */
/* 17. Implementation of Kruskal’s algorithm using greedy approach.[^1] */
/* 31. A smart farming system requires connecting multiple sensors across the farm with wiring or wireless links. Each possible connection has an associated cost. Implement Kruskal’s algorithm to determine the cheapest layout that connects all sensors efficiently.[^1] */

#include <stdio.h>
#include <stdlib.h>

static void printV(int v, int n)
{
	if (n <= 26) printf("%c", (char)('A' + v));
	else printf("%d", v);
}

typedef struct {
	int u;
	int v;
	int w;
} Edge;

static int findSet(int p[], int x)
{
	if (p[x] == x) return x;
	p[x] = findSet(p, p[x]);
	return p[x];
}

static void unionSet(int p[], int r[], int a, int b)
{
	a = findSet(p, a);
	b = findSet(p, b);
	if (a == b) return;
	if (r[a] < r[b]) p[a] = b;
	else if (r[a] > r[b]) p[b] = a;
	else {
		p[b] = a;
		r[a]++;
	}
}

static void sortEdgesByWeight(Edge e[], int m)
{
	int i, j;
	for (i = 0; i < m - 1; i++) {
		for (j = 0; j < m - 1 - i; j++) {
			if (e[j].w > e[j + 1].w) {
				Edge t = e[j];
				e[j] = e[j + 1];
				e[j + 1] = t;
			}
		}
	}
}

int main(void)
{
	int V, E, i;
	Edge *e;
	int *p, *r;
	int cnt = 0;
	int total = 0;

	printf("Enter number of vertices and edges: ");
	if (scanf("%d %d", &V, &E) != 2 || V <= 0 || E < 0) {
		printf("Invalid input.\n");
		return 1;
	}

	e = (Edge *)malloc((size_t)E * sizeof(Edge));
	p = (int *)malloc((size_t)V * sizeof(int));
	r = (int *)malloc((size_t)V * sizeof(int));
	if ((!e && E > 0) || !p || !r) {
		printf("Memory allocation failed.\n");
		free(e);
		free(p);
		free(r);
		return 1;
	}

	printf("Enter edges (u v w) with vertices 0..%d (undirected):\n", V - 1);
	for (i = 0; i < E; i++) {
		if (scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w) != 3) {
			printf("Invalid edge input.\n");
			free(e);
			free(p);
			free(r);
			return 1;
		}
		if (e[i].u < 0 || e[i].u >= V || e[i].v < 0 || e[i].v >= V) {
			printf("Invalid vertex in edge.\n");
			free(e);
			free(p);
			free(r);
			return 1;
		}
	}

	for (i = 0; i < V; i++) {
		p[i] = i;
		r[i] = 0;
	}

	sortEdgesByWeight(e, E);

	printf("\nMST edges (u - v : w):\n");
	for (i = 0; i < E && cnt < V - 1; i++) {
		int a = findSet(p, e[i].u);
		int b = findSet(p, e[i].v);
		if (a != b) {
			printV(e[i].u, V);
			printf(" - ");
			printV(e[i].v, V);
			printf(" : %d\n", e[i].w);
			total += e[i].w;
			unionSet(p, r, a, b);
			cnt++;
		}
	}

	if (cnt != V - 1) printf("Graph is disconnected; MST not possible for all vertices.\n");
	else printf("Total weight = %d\n", total);

	free(e);
	free(p);
	free(r);
	return 0;
}

/*
Complexity & classification:
- Problem type: minimum spanning tree (greedy)
- Class: P (polynomial-time)
- Time: O(E^2) as written (bubble sort edges) + near O(E α(V)) union-find
- Space: O(V + E)
- Notes: With an efficient sort, sorting becomes O(E log E).
*/
