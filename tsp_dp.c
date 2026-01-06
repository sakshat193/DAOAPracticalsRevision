/* Relevant questions: PDF Q23/Q27 (TSP DP variants) */
/* Also matches DAOA list items: 23, 27 */
/* Full text: */
/* 23. A delivery company uses a drone to distribute parcels to several drop-off locations. The drone must start from its base, visit every drop-off point exactly once, and return to the base while minimizing the total travel distance. Implement a Dynamic Programming–based Travelling Salesperson (TSP) algorithm to compute the optimal delivery route for the drone.[^1] */
/* 27. A company has a salesperson who must visit several client locations starting and ending at the office. The goal is to determine the route that covers all client visits with the least possible travel distance. Implement a Dynamic Programming–based Travelling Salesperson (TSP) algorithm to compute the shortest possible tour for the salesperson.[^1] */

#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000

/* Set to 1 to use the hard-coded distance matrix below. */
#define USE_MANUAL_MATRIX 0

static void printV(int v, int n)
{
	if (n <= 26) printf("%c", (char)('A' + v));
	else printf("%d", v);
}

static int tsp(int mask, int pos, int n, int **w, int **dp, int **next)
{
	if (mask == (1 << n) - 1) {
		if (w[pos][0] >= 0) return w[pos][0];
		return INF;
	}
	if (dp[mask][pos] != -1) return dp[mask][pos];

	int best = INF;
	int bestCity = -1;
	int city;
	for (city = 0; city < n; city++) {
		if (!(mask & (1 << city)) && w[pos][city] >= 0) {
			int cost = w[pos][city] + tsp(mask | (1 << city), city, n, w, dp, next);
			if (cost < best) {
				best = cost;
				bestCity = city;
			}
		}
	}
	if (bestCity != -1) next[mask][pos] = bestCity;
	dp[mask][pos] = best;
	return best;
}

int main(void)
{
	int n, i, j;
	int **w;
	int **dp, **next;
	int states;
	int ans;


#if USE_MANUAL_MATRIX
	/* Edit this matrix manually. Use -1 for no direct path. Diagonal can be 0. */
	n = 4;
	int manual[4][4] = {
		{0, 10, 15, 20},
		{10, 0, 35, 25},
		{15, 35, 0, 30},
		{20, 25, 30, 0}
	};
#else
	printf("Enter number of cities (suggest <= 15): ");
	if (scanf("%d", &n) != 1 || n <= 1 || n > 20) {
		printf("Invalid n.\n");
		return 1;
	}
#endif

	w = (int **)malloc((size_t)n * sizeof(int *));
	if (!w) {
		printf("Memory allocation failed.\n");
		return 1;
	}
	for (i = 0; i < n; i++) {
		w[i] = (int *)malloc((size_t)n * sizeof(int));
		if (!w[i]) {
			printf("Memory allocation failed.\n");
			for (j = 0; j < i; j++) free(w[j]);
			free(w);
			return 1;
		}
	}

	printf("Enter distance matrix (use -1 for no direct path):\n");
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
				return 1;
			}
#endif
			w[i][j] = x;
		}
	}

	states = 1 << n;
	dp = (int **)malloc((size_t)states * sizeof(int *));
	next = (int **)malloc((size_t)states * sizeof(int *));
	if (!dp || !next) {
		printf("Memory allocation failed.\n");
		for (i = 0; i < n; i++) free(w[i]);
		free(w);
		free(dp);
		free(next);
		return 1;
	}
	for (i = 0; i < states; i++) {
		dp[i] = (int *)malloc((size_t)n * sizeof(int));
		next[i] = (int *)malloc((size_t)n * sizeof(int));
		if (!dp[i] || !next[i]) {
			printf("Memory allocation failed.\n");
			for (j = 0; j <= i; j++) {
				free(dp[j]);
				free(next[j]);
			}
			free(dp);
			free(next);
			for (j = 0; j < n; j++) free(w[j]);
			free(w);
			return 1;
		}
		for (j = 0; j < n; j++) {
			dp[i][j] = -1;
			next[i][j] = -1;
		}
	}

	ans = tsp(1, 0, n, w, dp, next);
	if (ans >= INF) {
		printf("No Hamiltonian tour possible with given distances.\n");
	} else {
		int mask = 1;
		int pos = 0;
		printf("Minimum tour cost = %d\n", ans);
		printf("Tour: ");
		printV(0, n);
		printf(" ");
		while (1) {
			int nx = next[mask][pos];
			if (nx == -1) break;
			printf("-> ");
			printV(nx, n);
			printf(" ");
			mask |= (1 << nx);
			pos = nx;
			if (mask == (1 << n) - 1) break;
		}
		printf("-> ");
		printV(0, n);
		printf("\n");
	}

	for (i = 0; i < states; i++) {
		free(dp[i]);
		free(next[i]);
	}
	free(dp);
	free(next);
	for (i = 0; i < n; i++) free(w[i]);
	free(w);
	return 0;
}

/*
Complexity & classification:
- Problem type: Travelling Salesperson Problem (TSP) optimization
- Class: NP-hard (optimization); NP-complete (decision version: “tour cost <= K?”)
- Time: O(n^2 * 2^n) (bitmask DP)
- Space: O(n * 2^n) for DP tables
- Notes: This DP is exact but exponential; practical for small n.
*/
