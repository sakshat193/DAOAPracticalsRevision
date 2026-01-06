/* Relevant questions: PDF Q16/Q25 (Graph Coloring variants) */
/* Also matches DAOA list items: 16, 25 */
/* Full text: */
/* 16. Implementation of Graph Coloring problem to demonstrate Backtracking approach.[^1] */
/* 25. A digital mapping system needs to display different countries using colors. To avoid confusion, no two countries that share a border should be displayed in the same color. Design and implement a graph coloring algorithm to achieve this and find the minimum number of colors required.[^1] */

#include <stdio.h>
#include <stdlib.h>

/* Set to 1 to use the hard-coded adjacency matrix below. */
#define USE_MANUAL_MATRIX 0

static void printV(int v, int n)
{
	if (n <= 26) printf("%c", (char)('A' + v));
	else printf("%d", v);
}

static int isSafe(int v, int **g, int n, int color[], int c)
{
	int i;
	for (i = 0; i < n; i++) {
		if (g[v][i] && color[i] == c) return 0;
	}
	return 1;
}

static int colorUtil(int **g, int n, int m, int color[], int v)
{
	if (v == n) return 1;
	int c;
	for (c = 1; c <= m; c++) {
		if (isSafe(v, g, n, color, c)) {
			color[v] = c;
			if (colorUtil(g, n, m, color, v + 1)) return 1;
			color[v] = 0;
		}
	}
	return 0;
}

int main(void)
{
	int n, i, j;
	int **g;
	int *color;
	int m;

#if USE_MANUAL_MATRIX
	/* Edit this matrix manually. Use 0/1 for adjacency. Diagonal should be 0. */
	n = 5;
	int manual[5][5] = {
		{0, 1, 1, 1, 0},
		{1, 0, 1, 0, 1},
		{1, 1, 0, 1, 1},
		{1, 0, 1, 0, 0},
		{0, 1, 1, 0, 0}
	};
#else
	printf("Enter number of vertices: ");
	if (scanf("%d", &n) != 1 || n <= 0) {
		printf("Invalid n.\n");
		return 1;
	}
#endif

	g = (int **)malloc((size_t)n * sizeof(int *));
	color = (int *)malloc((size_t)n * sizeof(int));
	if (!g || !color) {
		printf("Memory allocation failed.\n");
		free(g);
		free(color);
		return 1;
	}
	for (i = 0; i < n; i++) {
		g[i] = (int *)malloc((size_t)n * sizeof(int));
		if (!g[i]) {
			printf("Memory allocation failed.\n");
			for (j = 0; j < i; j++) free(g[j]);
			free(g);
			free(color);
			return 1;
		}
	}

	printf("Enter adjacency matrix (0/1):\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			int x;
#if USE_MANUAL_MATRIX
			x = manual[i][j];
#else
			if (scanf("%d", &x) != 1) {
				printf("Invalid input.\n");
				for (i = 0; i < n; i++) free(g[i]);
				free(g);
				free(color);
				return 1;
			}
#endif
			g[i][j] = (x != 0);
		}
	}

	for (i = 0; i < n; i++) color[i] = 0;

	for (m = 1; m <= n; m++) {
		for (i = 0; i < n; i++) color[i] = 0;
		if (colorUtil(g, n, m, color, 0)) break;
	}

	printf("Minimum colors required = %d\n", m);
	printf("Coloring:\n");
	for (i = 0; i < n; i++) {
		printV(i, n);
		printf(" -> Color %d\n", color[i]);
	}

	for (i = 0; i < n; i++) free(g[i]);
	free(g);
	free(color);
	return 0;
}

/*
Complexity & classification:
- Problem type: graph coloring / chromatic number (backtracking)
- Class: NP-hard (optimization: minimum colors); NP-complete (decision: k-colorability)
- Time: Exponential in V in worst case (backtracking)
- Space: O(V^2) for matrix + O(V) for colors/recursion
- Notes: This searches for the minimum number of colors by trying m=1..V.
*/
