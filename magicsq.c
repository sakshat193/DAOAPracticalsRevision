/* Relevant questions: PDF Q11 (Magic Square Cost) */
/* Also matches DAOA list items: 11 */
/* Full text: */
/* 11. A magic square is an $n \times n$ matrix of distinct positive integers from 1 to $n^2$ where the sum of any row, column, or diagonal of length $n$ is always equal to the same number: the magic constant. You will be given a $3 \times 3$ matrix $S$ of integers in the inclusive range $[1, 9]$. You can convert any digit $a$ to any other digit $b$ in the range $[1, 9]$ at cost $|a - b|$. Given $S$, convert it into a magic square at minimal cost and print this cost. [^1] */

#include <stdio.h>
#include <stdlib.h>

static int absInt(int x) { return x < 0 ? -x : x; }

int main(void)
{
	int s[9];
	int i;

	printf("Enter 3x3 matrix values (9 integers):\n");
	for (i = 0; i < 9; i++) {
		if (scanf("%d", &s[i]) != 1) {
			printf("Invalid input.\n");
			return 1;
		}
	}

	int ms[8][9] = {
		{8, 1, 6, 3, 5, 7, 4, 9, 2},
		{6, 1, 8, 7, 5, 3, 2, 9, 4},
		{4, 9, 2, 3, 5, 7, 8, 1, 6},
		{2, 9, 4, 7, 5, 3, 6, 1, 8},
		{8, 3, 4, 1, 5, 9, 6, 7, 2},
		{4, 3, 8, 9, 5, 1, 2, 7, 6},
		{6, 7, 2, 1, 5, 9, 8, 3, 4},
		{2, 7, 6, 9, 5, 1, 4, 3, 8}
	};

	int best = 1000000000;
	int k;
	for (k = 0; k < 8; k++) {
		int cost = 0;
		for (i = 0; i < 9; i++) cost += absInt(s[i] - ms[k][i]);
		if (cost < best) best = cost;
	}

	printf("Minimum cost = %d\n", best);
	return 0;
}

/*
Complexity & classification:
- Problem type: brute-force over constant set (optimization)
- Class: P (constant time)
- Time: O(1) (checks 8 possible 3x3 magic squares)
- Space: O(1)
- Notes: Only valid for 3x3 input as specified.
*/
