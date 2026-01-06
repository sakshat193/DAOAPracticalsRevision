/* Relevant questions: PDF Q2 (Quick Sort) */
/* Also matches DAOA list items: 2 */
/* Full text: */
/* 2. Implement Quick sort and analyze its time complexity.[^1] */

#include <stdio.h>
#include <stdlib.h>

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

static void quickSort(int a[], int l, int r)
{
	if (l >= r) return;
	int p = partition(a, l, r);
	quickSort(a, l, p - 1);
	quickSort(a, p + 1, r);
}

int main(void)
{
	int n, i;
	int *a;

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

	quickSort(a, 0, n - 1);

	printf("Sorted array: ");
	for (i = 0; i < n; i++) printf("%d ", a[i]);
	printf("\n");

	free(a);
	return 0;
}

/*
Complexity & classification:
- Problem type: sorting (divide and conquer)
- Class: P (polynomial-time)
- Time: Best = O(n log n), Average = O(n log n), Worst = O(n^2)
- Space: O(log n) recursion (in-place partition)
- Notes: This uses a deterministic last-element pivot; worst-case often occurs on already-sorted input.
*/
