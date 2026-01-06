/* Relevant questions: PDF Q8/Q41 (N-Queens variants) */
/* Also matches DAOA list items: 8, 41 */
/* Full text: */
/* 8. Implement N-Queen problem to demonstrate Backtracking approach.[^1] */
/* 41. Design and code a solution for the N-Queens problem using Backtracking to show how conflicts can be avoided.[^1] */

#include <stdio.h>
#include <stdlib.h>

static int isSafe(int col[], int row, int c)
{
	int r;
	for (r = 0; r < row; r++) {
		int pc = col[r];
		if (pc == c) return 0;
		if (abs(pc - c) == abs(r - row)) return 0;
	}
	return 1;
}

static int solve(int col[], int n, int row)
{
	if (row == n) return 1;
	int c;
	for (c = 0; c < n; c++) {
		if (isSafe(col, row, c)) {
			col[row] = c;
			if (solve(col, n, row + 1)) return 1;
		}
	}
	return 0;
}

static void printBoard(int col[], int n)
{
	int r, c;
	for (r = 0; r < n; r++) {
		for (c = 0; c < n; c++) {
			printf("%c ", (col[r] == c) ? 'Q' : '.');
		}
		printf("\n");
	}
}

int main(void)
{
	int n;
	int *col;

	printf("Enter N (number of queens): ");
	if (scanf("%d", &n) != 1 || n <= 0) {
		printf("Invalid N.\n");
		return 1;
	}

	col = (int *)malloc((size_t)n * sizeof(int));
	if (!col) {
		printf("Memory allocation failed.\n");
		return 1;
	}

	if (!solve(col, n, 0)) {
		printf("No solution found for N=%d\n", n);
		free(col);
		return 0;
	}

	printf("One solution for N=%d:\n", n);
	printBoard(col, n);

	free(col);
	return 0;
}

/*
Complexity & classification:
- Problem type: constraint satisfaction (backtracking)
- Class: In NP (verification is polynomial); typical backtracking is exponential-time
- Time: Worst-case exponential (commonly cited ~O(n!))
- Space: O(n) for recursion + O(n) for column placements
- Notes: This prints one solution (stops after finding the first).
*/
