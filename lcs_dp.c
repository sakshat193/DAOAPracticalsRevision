/* Relevant questions: PDF Q6/Q39 (LCS variants) */
/* Also matches DAOA list items: 6, 39 */
/* Full text: */
/* 6. Implement Longest Common Subsequence algorithm.[^1] */
/* 39. A bioinformatics system compares two DNA sequences to identify common genetic patterns. Design and implement a program using the Longest Common Subsequence (LCS) algorithm to determine the longest matching subsequence between two given DNA sequences.[^1] */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int max2(int a, int b) { return a > b ? a : b; }

int main(void)
{
	char s1[1005], s2[1005];
	int m, n;
	int i, j;
	int **dp;
	char *lcs;
	int len;

	printf("Enter first string: ");
	if (scanf("%1000s", s1) != 1) {
		printf("Invalid input.\n");
		return 1;
	}
	printf("Enter second string: ");
	if (scanf("%1000s", s2) != 1) {
		printf("Invalid input.\n");
		return 1;
	}

	m = (int)strlen(s1);
	n = (int)strlen(s2);

	dp = (int **)malloc((size_t)(m + 1) * sizeof(int *));
	if (!dp) {
		printf("Memory allocation failed.\n");
		return 1;
	}
	for (i = 0; i <= m; i++) {
		dp[i] = (int *)malloc((size_t)(n + 1) * sizeof(int));
		if (!dp[i]) {
			printf("Memory allocation failed.\n");
			for (j = 0; j < i; j++) free(dp[j]);
			free(dp);
			return 1;
		}
	}

	for (i = 0; i <= m; i++) dp[i][0] = 0;
	for (j = 0; j <= n; j++) dp[0][j] = 0;

	for (i = 1; i <= m; i++) {
		for (j = 1; j <= n; j++) {
			if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max2(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	len = dp[m][n];
	lcs = (char *)malloc((size_t)len + 1);
	if (!lcs) {
		printf("Memory allocation failed.\n");
		for (i = 0; i <= m; i++) free(dp[i]);
		free(dp);
		return 1;
	}
	lcs[len] = '\0';

	int x = m, y = n;
	while (x > 0 && y > 0) {
		if (s1[x - 1] == s2[y - 1]) {
			lcs[--len] = s1[x - 1];
			x--;
			y--;
		} else if (dp[x - 1][y] >= dp[x][y - 1]) {
			x--;
		} else {
			y--;
		}
	}

	printf("LCS length = %d\n", dp[m][n]);
	printf("One LCS = %s\n", lcs);

	free(lcs);
	for (i = 0; i <= m; i++) free(dp[i]);
	free(dp);
	return 0;
}

/*
Complexity & classification:
- Problem type: dynamic programming (sequence alignment)
- Class: P (polynomial-time)
- Time: O(mn)
- Space: O(mn)
- Notes: This also reconstructs one LCS by backtracking the DP table.
*/
