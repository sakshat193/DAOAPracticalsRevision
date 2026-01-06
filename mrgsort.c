/* Relevant questions: PDF Q1 (Merge Sort) */
/* Also matches DAOA list items: 1 */
/* Full text: */
/* 1. Implement Merge sort and analyze its time complexity.[^1] */

#include <stdio.h>
#include <stdlib.h>

static void merge(int a[], int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;
	int *L = (int *)malloc((size_t)n1 * sizeof(int));
	int *R = (int *)malloc((size_t)n2 * sizeof(int));
	int i, j, k;

	if (!L || !R) {
		printf("Memory allocation failed.\n");
		free(L);
		free(R);
		exit(1);
	}

	for (i = 0; i < n1; i++) L[i] = a[l + i];
	for (j = 0; j < n2; j++) R[j] = a[m + 1 + j];

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) a[k++] = L[i++];
		else a[k++] = R[j++];
	}
	while (i < n1) a[k++] = L[i++];
	while (j < n2) a[k++] = R[j++];

	free(L);
	free(R);
}

static void mergeSort(int a[], int l, int r)
{
	if (l >= r) return;
	int m = l + (r - l) / 2;
	mergeSort(a, l, m);
	mergeSort(a, m + 1, r);
	merge(a, l, m, r);
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

	mergeSort(a, 0, n - 1);

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
- Time: Best/Average/Worst = O(n log n)
- Space: O(n) auxiliary (temporary arrays) + O(log n) recursion
- Notes: Stable sorting (as implemented with <= in merge).
*/
