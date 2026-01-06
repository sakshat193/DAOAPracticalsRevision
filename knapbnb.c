/* Relevant questions: PDF Q9 (0/1 Knapsack - Branch and Bound) */
/* Also matches DAOA list items: 9 */
/* Full text: */
/* 9. Implement and demonstrate the working of the Branch and Bound algorithm with the implementation of 0/1 Knapsack.[^1] */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int id;
	int w;
	int v;
	double r;
} Item;

typedef struct {
	int lvl;
	int w;
	int v;
	double b;
	unsigned int mask;
} Node;

static int cmpRatioDesc(const void *a, const void *b)
{
	double x = ((const Item *)a)->r;
	double y = ((const Item *)b)->r;
	return (x < y) - (x > y);
}

static double bound(Node u, int n, int W, Item it[])
{
	if (u.w >= W) return 0.0;
	double prof = (double)u.v;
	int totw = u.w;
	int i = u.lvl + 1;
	while (i < n && totw + it[i].w <= W) {
		totw += it[i].w;
		prof += it[i].v;
		i++;
	}
	if (i < n) {
		int rem = W - totw;
		prof += it[i].r * rem;
	}
	return prof;
}

int main(void)
{
	int n, W, i;
	Item *it;
	Node *q;
	int qn = 0;
	int best = 0;
	unsigned int bestMask = 0;

	printf("Enter number of items: ");
	if (scanf("%d", &n) != 1 || n <= 0 || n > 31) {
		printf("Invalid n (use 1..31).\n");
		return 1;
	}
	printf("Enter knapsack capacity: ");
	if (scanf("%d", &W) != 1 || W < 0) {
		printf("Invalid capacity.\n");
		return 1;
	}

	it = (Item *)malloc((size_t)n * sizeof(Item));
	q = (Node *)malloc((size_t)(2 * n + 5) * sizeof(Node));
	if (!it || !q) {
		printf("Memory allocation failed.\n");
		free(it);
		free(q);
		return 1;
	}

	printf("Enter weight and value for each item:\n");
	for (i = 0; i < n; i++) {
		printf("Item %d (w v): ", i + 1);
		if (scanf("%d %d", &it[i].w, &it[i].v) != 2 || it[i].w <= 0) {
			printf("Invalid input. Weight must be > 0.\n");
			free(it);
			free(q);
			return 1;
		}
		it[i].id = i + 1;
		it[i].r = (double)it[i].v / (double)it[i].w;
	}

	qsort(it, (size_t)n, sizeof(Item), cmpRatioDesc);

	Node root;
	root.lvl = -1;
	root.w = 0;
	root.v = 0;
	root.mask = 0;
	root.b = bound(root, n, W, it);
	q[qn++] = root;

	while (qn > 0) {
		/* Extract node with maximum bound (simple linear scan priority queue) */
		int bi = 0;
		int k;
		for (k = 1; k < qn; k++) if (q[k].b > q[bi].b) bi = k;
		Node u = q[bi];
		q[bi] = q[--qn];

		if (u.b <= best) continue;
		if (u.lvl == n - 1) continue;

		Node v;
		v.lvl = u.lvl + 1;

		/* Take item v.lvl */
		v.w = u.w + it[v.lvl].w;
		v.v = u.v + it[v.lvl].v;
		v.mask = u.mask | (1u << v.lvl);
		if (v.w <= W && v.v > best) {
			best = v.v;
			bestMask = v.mask;
		}
		v.b = bound(v, n, W, it);
		if (v.b > best) q[qn++] = v;

		/* Don't take item v.lvl */
		v.w = u.w;
		v.v = u.v;
		v.mask = u.mask;
		v.b = bound(v, n, W, it);
		if (v.b > best) q[qn++] = v;
	}

	printf("Maximum value = %d\n", best);
	printf("Selected items (by input index): ");
	int any = 0;
	for (i = 0; i < n; i++) {
		if (bestMask & (1u << i)) {
			printf("%d ", it[i].id);
			any = 1;
		}
	}
	if (!any) printf("(none)");
	printf("\n");

	free(it);
	free(q);
	return 0;
}

/*
Complexity & classification:
- Problem type: 0/1 knapsack optimization (branch and bound)
- Class: NP-hard (optimization); NP-complete (decision version)
- Time: Worst-case exponential; often prunes many nodes using bounds
- Space: O(number of live nodes) (queue) + O(n) items
- Notes: Uses fractional-knapsack upper bound; priority queue implemented by linear scan.
*/
