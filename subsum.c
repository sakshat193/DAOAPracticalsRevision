/* Relevant questions: PDF Q13/Q24/Q35/Q38 (Sum of Subsets variants) */
/* Also matches DAOA list items: 13, 24, 35, 38 */
/* Full text: */
/* 13. Implementation of Sum of Subset problem to demonstrate Backtracking approach.[^1] */
/* 24. A logistics company needs to pack items into a shipment container that has a fixed weight capacity. You are given a list of item weights, and the goal is to identify all possible combinations of items whose total weight exactly matches the container's capacity. Implement a backtracking algorithm to generate every valid subset that sums to the target weight.[^1] */
/* 35. A cashier system needs to generate all possible ways to make a specific payment amount using a set of available coins, where each coin is allowed to be used only one time. Write a Dynamic Programming algorithm to solve this problem.[^1] */
/* 38. A budgeting application needs to verify whether a combination of expense amounts can exactly match a given budget value. Write a program to solve this problem using the Sum of Subsets algorithm with Backtracking.[^1] */

#include <stdio.h>
#include <stdlib.h>

static int cmpIntAsc(const void *a, const void *b)
{
	int x = *(const int *)a;
	int y = *(const int *)b;
	return (x > y) - (x < y);
}

static void backtrack(int a[], int n, int idx, int target, int sum, int take[])
{
	if (sum == target) {
		int i;
		printf("{ ");
		for (i = 0; i < idx; i++) {
			if (take[i]) printf("%d ", a[i]);
		}
		printf("}\n");
		return;
	}
	if (idx == n) return;
	if (sum > target) return;

	/* Include a[idx] */
	take[idx] = 1;
	backtrack(a, n, idx + 1, target, sum + a[idx], take);

	/* Exclude a[idx] */
	take[idx] = 0;
	backtrack(a, n, idx + 1, target, sum, take);
}

int main(void)
{
	int n, i, target;
	int *a;
	int *take;

	printf("Enter number of elements: ");
	if (scanf("%d", &n) != 1 || n <= 0) {
		printf("Invalid n.\n");
		return 1;
	}
	printf("Enter target sum: ");
	if (scanf("%d", &target) != 1 || target < 0) {
		printf("Invalid target.\n");
		return 1;
	}

	a = (int *)malloc((size_t)n * sizeof(int));
	take = (int *)malloc((size_t)n * sizeof(int));
	if (!a || !take) {
		printf("Memory allocation failed.\n");
		free(a);
		free(take);
		return 1;
	}

	printf("Enter %d non-negative integers: ", n);
	for (i = 0; i < n; i++) {
		if (scanf("%d", &a[i]) != 1 || a[i] < 0) {
			printf("Invalid input.\n");
			free(a);
			free(take);
			return 1;
		}
		take[i] = 0;
	}

	/* Sorting is optional; keeps output more organized. */
	qsort(a, (size_t)n, sizeof(int), cmpIntAsc);

	printf("Subsets with sum %d:\n", target);
	backtrack(a, n, 0, target, 0, take);

	free(a);
	free(take);
	return 0;
}

/*
Complexity & classification:
- Problem type: subset sum / sum of subsets (backtracking enumeration)
- Class: NP-complete (decision version: “subset sum == target?”)
- Time: Worst-case O(2^n)
- Space: O(n) recursion + O(n) selection array
- Notes: This enumerates all matching subsets (can be exponential output size).
*/
