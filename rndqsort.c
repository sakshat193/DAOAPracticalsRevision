/* Relevant questions: PDF Q3 (Randomized Quick Sort) */
/* Also matches DAOA list items: 3 */
/* Full text: */
/* 3. Implement randomized Quick Sort.[^1] */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static void swap(int *x, int *y)
{
	int t = *x;
	*x = *y;
	*y = t;
}

static int partition(int a[], int l, int r)
{
	int pivot = a[r];
	int i = l - 1;
	int j;
	for (j = l; j < r; j++) {
		if (a[j] <= pivot) {
			i++;
			swap(&a[i], &a[j]);
		}
	}
	swap(&a[i + 1], &a[r]);
	return i + 1;
}

static int randomizedPartition(int a[], int l, int r)
{
	int idx = l + rand() % (r - l + 1);
	swap(&a[idx], &a[r]);
	return partition(a, l, r);
}

static void randQuickSort(int a[], int l, int r)
{
	if (l >= r) return;
	int p = randomizedPartition(a, l, r);
	randQuickSort(a, l, p - 1);
	randQuickSort(a, p + 1, r);
}

int main(void)
{
	int n, i;
	int *a;

	srand((unsigned)time(NULL));

	printf("Enter number of elements: ");
	if (scanf("%d", &n) != 1 || n <= 0) {
		printf("Invalid n.\n");
		return 1;
	}

	a = (int *)malloc((size_t)n * sizeof(int));
	if (!a) {
		printf("Memory allocation failed.\n");
		return 1;
	}

	printf("Enter %d integers: ", n);
	for (i = 0; i < n; i++) {
		if (scanf("%d", &a[i]) != 1) {
			printf("Invalid input.\n");
			free(a);
			return 1;
		}
	}

	randQuickSort(a, 0, n - 1);

	printf("Sorted array: ");
	for (i = 0; i < n; i++) printf("%d ", a[i]);
	printf("\n");

	free(a);
	return 0;
}

/*
Complexity & classification:
- Problem type: sorting (randomized divide and conquer)
- Class: P (polynomial-time)
- Time: Expected O(n log n), Worst-case O(n^2)
- Space: O(log n) expected recursion depth
- Notes: Random pivot reduces probability of hitting worst-case on adversarial inputs.
*/
