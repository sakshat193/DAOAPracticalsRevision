/* Relevant questions: PDF Q7 (Floyd–Warshall) */
/* Also matches DAOA list items: 7 */
/* Full text: */
/* 7. Implement Floyd–Warshall algorithm to find all-pairs shortest path.[^1] */

#include <stdio.h>
#include <stdlib.h>

/* Set to 1 to use the hard-coded adjacency matrix below. */
#define USE_MANUAL_MATRIX 0

#define INF 1000000000

int main(void)
{
	int n, i, j, k;
	int **d;

#if USE_MANUAL_MATRIX
	/* Edit this matrix manually. Use -1 for no edge. Diagonal can be 0. */
	n = 4;
	int manual[4][4] = {
		{0, 5, -1, 10},
		{-1, 0, 3, -1},
		{-1, -1, 0, 1},
		{-1, -1, -1, 0}
	};
#else

	printf("Enter number of vertices: ");
	if (scanf("%d", &n) != 1 || n <= 0) {
		printf("Invalid n.\n");
		return 1;
	}
#endif

	d = (int **)malloc((size_t)n * sizeof(int *));
	if (!d) {
		printf("Memory allocation failed.\n");
		return 1;
	}
	for (i = 0; i < n; i++) {
		d[i] = (int *)malloc((size_t)n * sizeof(int));
		if (!d[i]) {
			printf("Memory allocation failed.\n");
			for (j = 0; j < i; j++) free(d[j]);
			free(d);
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
				for (i = 0; i < n; i++) free(d[i]);
				free(d);
				return 1;
			}
#endif
			if (i == j) d[i][j] = 0;
			else if (x < 0) d[i][j] = INF;
			else d[i][j] = x;
		}
	}

	for (k = 0; k < n; k++) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (d[i][k] < INF && d[k][j] < INF && d[i][k] + d[k][j] < d[i][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}

	printf("\nAll-pairs shortest path matrix:\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (d[i][j] >= INF / 2) printf("INF ");
			else printf("%d ", d[i][j]);
		}
		printf("\n");
	}

	for (i = 0; i < n; i++) free(d[i]);
	free(d);
	return 0;
}

/*
Complexity & classification:
- Problem type: shortest path (all-pairs)
- Class: P (polynomial-time)
- Time: O(V^3)
- Space: O(V^2)
- Notes: Works with negative edge weights (but not negative cycles).
*/
