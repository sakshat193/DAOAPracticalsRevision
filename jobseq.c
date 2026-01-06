/* Relevant questions: PDF Q14/Q22/Q42/Q43 (Job Sequencing variants) */
/* Also matches DAOA list items: 14, 22, 42, 43 */
/* Full text: */
/* 14. Implementation of Job Sequencing with deadline using greedy approach.[^1] */
/* 22. Implement a greedy algorithm to schedule delivery jobs for a courier company to maximize total profit before deadlines.[^1] */
/* 42. A software company receives several client tasks, each with a fixed deadline and payment amount. The company can complete only one task per time slot. Design and implement a program using the Greedy approach to determine the most profitable job sequence.[^1] */
/* 43. A data processing center must execute a set of tasks where each task has a deadline and an associated profit. Only one task can be done at a time. Implement the Job Sequencing with Deadlines algorithm using a Greedy strategy to get the maximum profit.[^1] */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int id;
	int d;
	int p;
} Job;

static void sortByProfitDesc(Job a[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - 1 - i; j++) {
			if (a[j].p < a[j + 1].p) {
				Job t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
}

int main(void)
{
	int n, i, j;
	Job *a;
	int maxd = 0;
	int *slot;
	int totalProfit = 0;
	int jobCount = 0;

	printf("Enter number of jobs: ");
	if (scanf("%d", &n) != 1 || n <= 0) {
		printf("Invalid n.\n");
		return 1;
	}

	a = (Job *)malloc((size_t)n * sizeof(Job));
	if (!a) {
		printf("Memory allocation failed.\n");
		return 1;
	}

	printf("Enter deadline and profit for each job:\n");
	for (i = 0; i < n; i++) {
		int d, p;
		printf("Job %d (d p): ", i + 1);
		if (scanf("%d %d", &d, &p) != 2 || d <= 0) {
			printf("Invalid input. Deadline must be > 0.\n");
			free(a);
			return 1;
		}
		a[i].id = i + 1;
		a[i].d = d;
		a[i].p = p;
		if (d > maxd) maxd = d;
	}

	sortByProfitDesc(a, n);

	slot = (int *)malloc((size_t)(maxd + 1) * sizeof(int));
	if (!slot) {
		printf("Memory allocation failed.\n");
		free(a);
		return 1;
	}
	for (i = 0; i <= maxd; i++) slot[i] = -1;

	for (i = 0; i < n; i++) {
		for (j = a[i].d; j >= 1; j--) {
			if (j <= maxd && slot[j] == -1) {
				slot[j] = i;
				totalProfit += a[i].p;
				jobCount++;
				break;
			}
		}
	}

	printf("\nSelected job sequence (time slot -> job id):\n");
	for (i = 1; i <= maxd; i++) {
		if (slot[i] != -1) {
			printf("Slot %d -> Job %d (d=%d, p=%d)\n", i, a[slot[i]].id, a[slot[i]].d, a[slot[i]].p);
		}
	}
	printf("\nJobs done: %d\n", jobCount);
	printf("Maximum profit: %d\n", totalProfit);

	free(slot);
	free(a);
	return 0;
}

/*
Complexity & classification:
- Problem type: scheduling optimization (greedy)
- Class: P (polynomial-time) for this greedy algorithm
- Time: O(n^2) as written (bubble sort by profit) + O(n * maxDeadline) slot assignment
- Space: O(n + maxDeadline)
- Notes: With an efficient sort, sorting becomes O(n log n).
*/
