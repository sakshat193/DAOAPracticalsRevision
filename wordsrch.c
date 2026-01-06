/* Relevant questions: PDF Q10 (Word Search in Grid) */
/* Also matches DAOA list items: 10 */
/* Full text: */
/* 10. Given an $m \times n$ grid of characters `board` and a string `word`, return true if `word` exists in the grid. The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.[^1] */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int dfs(char **b, int m, int n, int r, int c, const char *w, int k, int **vis)
{
	if (w[k] == '\0') return 1;
	if (r < 0 || r >= m || c < 0 || c >= n) return 0;
	if (vis[r][c]) return 0;
	if (b[r][c] != w[k]) return 0;

	vis[r][c] = 1;
	int ok = dfs(b, m, n, r + 1, c, w, k + 1, vis) ||
			dfs(b, m, n, r - 1, c, w, k + 1, vis) ||
			dfs(b, m, n, r, c + 1, w, k + 1, vis) ||
			dfs(b, m, n, r, c - 1, w, k + 1, vis);
	vis[r][c] = 0;
	return ok;
}

int main(void)
{
	int m, n, i, j;
	char word[1005];
	char **b;
	int **vis;

	printf("Enter rows and columns (m n): ");
	if (scanf("%d %d", &m, &n) != 2 || m <= 0 || n <= 0) {
		printf("Invalid m/n.\n");
		return 1;
	}
	printf("Enter word to search: ");
	if (scanf("%1000s", word) != 1) {
		printf("Invalid word.\n");
		return 1;
	}

	b = (char **)malloc((size_t)m * sizeof(char *));
	vis = (int **)malloc((size_t)m * sizeof(int *));
	if (!b || !vis) {
		printf("Memory allocation failed.\n");
		free(b);
		free(vis);
		return 1;
	}
	for (i = 0; i < m; i++) {
		b[i] = (char *)malloc((size_t)n * sizeof(char));
		vis[i] = (int *)malloc((size_t)n * sizeof(int));
		if (!b[i] || !vis[i]) {
			printf("Memory allocation failed.\n");
			for (j = 0; j <= i; j++) {
				free(b[j]);
				free(vis[j]);
			}
			free(b);
			free(vis);
			return 1;
		}
		for (j = 0; j < n; j++) vis[i][j] = 0;
	}

	printf("Enter grid characters row-wise (no spaces).\n");
	for (i = 0; i < m; i++) {
		char row[1005];
		printf("Row %d: ", i + 1);
		if (scanf("%1000s", row) != 1 || (int)strlen(row) != n) {
			printf("Invalid row. Must be exactly %d characters.\n", n);
			for (i = 0; i < m; i++) {
				free(b[i]);
				free(vis[i]);
			}
			free(b);
			free(vis);
			return 1;
		}
		for (j = 0; j < n; j++) b[i][j] = row[j];
	}

	int found = 0;
	for (i = 0; i < m && !found; i++) {
		for (j = 0; j < n && !found; j++) {
			if (dfs(b, m, n, i, j, word, 0, vis)) found = 1;
		}
	}

	printf(found ? "true\n" : "false\n");

	for (i = 0; i < m; i++) {
		free(b[i]);
		free(vis[i]);
	}
	free(b);
	free(vis);
	return 0;
}

/*
Complexity & classification:
- Problem type: grid search (backtracking / DFS)
- Class: Exponential-time backtracking in worst case (in NP)
- Time: O(mn * 4^L) worst-case, where L = length of word
- Space: O(mn) for visited + O(L) recursion depth
- Notes: Adjacency is 4-directional; each cell used at most once per path.
*/
