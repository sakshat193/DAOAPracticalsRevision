/* Relevant questions: PDF Q21/Q26 (0/1 Knapsack DP variants) */
/* Also matches DAOA list items: 21, 26 */
/* Full text: */
/* 21. Implement 0/1 Knapsack problem using Dynamic Programming.[^1] */
/* 26. A traveler is carrying a backpack that can hold only a limited amount of weight. A list of items is provided, each with a specific weight and value. Use the 0/1 Knapsack Dynamic Programming approach to determine which items should be chosen to achieve the highest total value without exceeding the backpack’s weight capacity.[^1] */

#include <stdio.h>
#include <stdlib.h>

static int max2(int a, int b) { return a > b ? a : b; }

int main(void)
{
	int n, W;
	int i, w;
	int *wt, *val;
	int **dp;

	printf("Enter number of items: ");
	if (scanf("%d", &n) != 1 || n <= 0) {
		printf("Invalid n.\n");
		return 1;
	}
	printf("Enter knapsack capacity: ");
	if (scanf("%d", &W) != 1 || W < 0) {
		printf("Invalid capacity.\n");
		return 1;
	}

	wt = (int *)malloc((size_t)(n + 1) * sizeof(int));
	val = (int *)malloc((size_t)(n + 1) * sizeof(int));
	if (!wt || !val) {
		printf("Memory allocation failed.\n");
		free(wt);
		free(val);
		return 1;
	}

	printf("Enter weight and value for each item:\n");
	for (i = 1; i <= n; i++) {
		printf("Item %d (w v): ", i);
		if (scanf("%d %d", &wt[i], &val[i]) != 2 || wt[i] < 0) {
			printf("Invalid input.\n");
			free(wt);
			free(val);
			return 1;
		}
	}

	dp = (int **)malloc((size_t)(n + 1) * sizeof(int *));
	if (!dp) {
		printf("Memory allocation failed.\n");
		free(wt);
		free(val);
		return 1;
	}
	for (i = 0; i <= n; i++) {
		dp[i] = (int *)malloc((size_t)(W + 1) * sizeof(int));
		if (!dp[i]) {
			printf("Memory allocation failed.\n");
			for (w = 0; w < i; w++) free(dp[w]);
			free(dp);
			free(wt);
			free(val);
			return 1;
		}
	}

	for (w = 0; w <= W; w++) dp[0][w] = 0;
	for (i = 1; i <= n; i++) {
		dp[i][0] = 0;
		for (w = 1; w <= W; w++) {
			if (wt[i] <= w) dp[i][w] = max2(dp[i - 1][w], val[i] + dp[i - 1][w - wt[i]]);
			else dp[i][w] = dp[i - 1][w];
		}
	}

	printf("Maximum value = %d\n", dp[n][W]);

	printf("Selected items (one optimal set): ");
	int remW = W;
	int any = 0;
	for (i = n; i >= 1; i--) {
		if (dp[i][remW] != dp[i - 1][remW]) {
			printf("%d ", i);
			remW -= wt[i];
			any = 1;
		}
	}
	if (!any) printf("(none)");
	printf("\n");

	for (i = 0; i <= n; i++) free(dp[i]);
	free(dp);
	free(wt);
	free(val);
	return 0;
}

/*
Complexity & classification:
- Problem type: 0/1 knapsack optimization (dynamic programming)
- Class: NP-hard (optimization); NP-complete (decision version)
- Time: O(nW) (pseudo-polynomial)
- Space: O(nW)
- Notes: This DP is efficient when capacity W is small/moderate.
*/
