/* Relevant questions: PDF Q19/Q32 (Activity Selection variants) */
/* Also matches DAOA list items: 19, 32 */
/* Full text: */
/* 19. Implementation of an algorithm to solve Activity Selection problem using greedy approach.[^1] */
/* 32. A conference organizer has multiple talks to schedule in a single hall, each with a start and end time. Implement a greedy-based Activity Selection algorithm to select the maximum number of talks that can be held in the hall without any time conflicts.[^1] */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int id;
	int s;
	int f;
} Act;

static void sortByFinishAsc(Act a[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - 1 - i; j++) {
			if (a[j].f > a[j + 1].f) {
				Act t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
}

int main(void)
{
	int n, i;
	Act *a;

	printf("Enter number of activities: ");
	if (scanf("%d", &n) != 1 || n <= 0) {
		printf("Invalid n.\n");
		return 1;
	}

	a = (Act *)malloc((size_t)n * sizeof(Act));
	if (!a) {
		printf("Memory allocation failed.\n");
		return 1;
	}

	printf("Enter start and finish time for each activity:\n");
	for (i = 0; i < n; i++) {
		int s, f;
		printf("Activity %d (s f): ", i + 1);
		if (scanf("%d %d", &s, &f) != 2 || f < s) {
			printf("Invalid input. Need f >= s.\n");
			free(a);
			return 1;
		}
		a[i].id = i + 1;
		a[i].s = s;
		a[i].f = f;
	}

	sortByFinishAsc(a, n);

	printf("\nSelected activities (max non-overlapping):\n");
	int lastFinish = -2147483647;
	int count = 0;
	for (i = 0; i < n; i++) {
		if (a[i].s >= lastFinish) {
			printf("Activity %d: [%d, %d]\n", a[i].id, a[i].s, a[i].f);
			lastFinish = a[i].f;
			count++;
		}
	}
	printf("\nTotal selected: %d\n", count);

	free(a);
	return 0;
}

/*
Complexity & classification:
- Problem type: scheduling / interval selection (greedy)
- Class: P (polynomial-time)
- Time: O(n^2) as written (bubble sort by finish time) + O(n) selection
- Space: O(n)
- Notes: With an efficient sort, time becomes O(n log n).
*/
