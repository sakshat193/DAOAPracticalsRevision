/* Relevant questions: PDF Q33/Q34 (Coin Change - minimum coins, unlimited supply) */
/* Also matches DAOA list items: 33, 34 */
/* Full text: */
/* 33. A digital payment application needs to calculate the minimum number of coins required to make a specific payment amount. The system has an unlimited supply of given coin denominations. Design and implement a Dynamic Programming solution to determine the minimum coins needed.[^1] */
/* 34. A vending machine must return change efficiently to customers. Given different coin values and a target amount, implement a Dynamic Programming approach that computes the minimum number of coins required to make the exact change.[^1] */

#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000

int main(void)
{
	int n, amt, i;
	int *coin;
	int *dp;
	int *pick;

	printf("Enter number of coin denominations: ");
	if (scanf("%d", &n) != 1 || n <= 0) {
		printf("Invalid n.\n");
		return 1;
	}
	printf("Enter target amount: ");
	if (scanf("%d", &amt) != 1 || amt < 0) {
		printf("Invalid amount.\n");
		return 1;
	}

	coin = (int *)malloc((size_t)n * sizeof(int));
	dp = (int *)malloc((size_t)(amt + 1) * sizeof(int));
	pick = (int *)malloc((size_t)(amt + 1) * sizeof(int));
	if (!coin || !dp || !pick) {
		printf("Memory allocation failed.\n");
		free(coin);
		free(dp);
		free(pick);
		return 1;
	}

	printf("Enter %d coin values: ", n);
	for (i = 0; i < n; i++) {
		if (scanf("%d", &coin[i]) != 1 || coin[i] <= 0) {
			printf("Invalid coin value.\n");
			free(coin);
			free(dp);
			free(pick);
			return 1;
		}
	}

	dp[0] = 0;
	pick[0] = -1;
	for (i = 1; i <= amt; i++) {
		dp[i] = INF;
		pick[i] = -1;
	}

	for (i = 1; i <= amt; i++) {
		int j;
		for (j = 0; j < n; j++) {
			int c = coin[j];
			if (c <= i && dp[i - c] + 1 < dp[i]) {
				dp[i] = dp[i - c] + 1;
				pick[i] = c;
			}
		}
	}

	if (dp[amt] >= INF || (amt > 0 && pick[amt] == -1)) {
		printf("Not possible to make amount %d with given coins.\n", amt);
	} else {
		printf("Minimum coins required = %d\n", dp[amt]);
		printf("One optimal set of coins: ");
		int x = amt;
		while (x > 0) {
			int c = pick[x];
			if (c == -1) break;
			printf("%d ", c);
			x -= c;
		}
		printf("\n");
	}

	free(coin);
	free(dp);
	free(pick);
	return 0;
}

/*
Complexity & classification:
- Problem type: coin change (minimum coins, unbounded) (dynamic programming)
- Class: P (polynomial-time) for this DP formulation
- Time: O(n * amount)
- Space: O(amount)
- Notes: This solves the "minimum coins" variant with unlimited supply.
*/
