/* Relevant questions: PDF Q12 (Tree Edge Cutting) */
/* Also matches DAOA list items: 12 */
/* Full text: */
/* 12. There is an undirected tree where each vertex is numbered from 1 to $n$, and each contains a data value. The sum of a tree is the sum of all its nodes' data values. If an edge is cut, two smaller trees are formed. The difference between two trees is the absolute value of the difference in their sums. Given a tree, determine which edge to cut so that the resulting trees have a minimal difference between them, then return that difference.[^1] */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int to;
	int next;
} Edge;

static int *head;
static Edge *e;
static int ec;
static int *val;
static long long *sub;
static int n;
static long long total;
static long long best;

static void addEdge(int u, int v)
{
	e[ec].to = v;
	e[ec].next = head[u];
	head[u] = ec++;
}

static void dfs(int u, int p)
{
	sub[u] = val[u];
	int id;
	for (id = head[u]; id != -1; id = e[id].next) {
		int v = e[id].to;
		if (v == p) continue;
		dfs(v, u);
		sub[u] += sub[v];
		/* Cutting edge (u - v) separates subtree v from rest */
		long long diff = total - 2LL * sub[v];
		if (diff < 0) diff = -diff;
		if (diff < best) best = diff;
	}
}

int main(void)
{
	int i;

	printf("Enter number of nodes n: ");
	if (scanf("%d", &n) != 1 || n <= 1) {
		printf("Invalid n.\n");
		return 1;
	}

	val = (int *)malloc((size_t)(n + 1) * sizeof(int));
	sub = (long long *)malloc((size_t)(n + 1) * sizeof(long long));
	head = (int *)malloc((size_t)(n + 1) * sizeof(int));
	e = (Edge *)malloc((size_t)(2 * (n - 1)) * sizeof(Edge));
	if (!val || !sub || !head || !e) {
		printf("Memory allocation failed.\n");
		free(val);
		free(sub);
		free(head);
		free(e);
		return 1;
	}

	for (i = 1; i <= n; i++) head[i] = -1;
	ec = 0;

	printf("Enter %d node values (1..n): ", n);
	total = 0;
	for (i = 1; i <= n; i++) {
		if (scanf("%d", &val[i]) != 1) {
			printf("Invalid input.\n");
			free(val);
			free(sub);
			free(head);
			free(e);
			return 1;
		}
		total += val[i];
	}

	printf("Enter %d edges (u v) for an undirected tree:\n", n - 1);
	for (i = 0; i < n - 1; i++) {
		int u, v;
		if (scanf("%d %d", &u, &v) != 2 || u < 1 || u > n || v < 1 || v > n) {
			printf("Invalid edge input.\n");
			free(val);
			free(sub);
			free(head);
			free(e);
			return 1;
		}
		addEdge(u, v);
		addEdge(v, u);
	}

	best = (1LL << 62);
	dfs(1, 0);

	printf("Minimum difference after cutting one edge = %lld\n", best);

	free(val);
	free(sub);
	free(head);
	free(e);
	return 0;
}

/*
Complexity & classification:
- Problem type: tree DP / graph traversal
- Class: P (polynomial-time)
- Time: O(n)
- Space: O(n)
- Notes: Computes subtree sums via DFS and checks each cut (parent-child edge).
*/
