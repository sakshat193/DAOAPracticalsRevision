/* Relevant questions: PDF Q4/Q40 (Fractional Knapsack variants) */
/* Also matches DAOA list items: 4, 40 */
/* Full text: */
/* 4. Implement the fractional knapsack problem by applying a greedy approach.[^1] */
/* 40. A delivery company has a truck with limited carrying capacity. Each package has a weight and a profit value, and the company is allowed to take fractions of packages if needed. Write a program using the Greedy approach to maximize the total profit.[^1] */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int id;
	double w;
	double p;
	double r;
} Item;

static void sortByRatioDesc(Item a[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - 1 - i; j++) {
			if (a[j].r < a[j + 1].r) {
				Item t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
}

int main(void)
{
	int n, i;
	double cap;
	Item *a;
	double total = 0.0;

	printf("Enter number of items: ");
	if (scanf("%d", &n) != 1 || n <= 0) {
		printf("Invalid n.\n");
		return 1;
	}
	printf("Enter knapsack capacity: ");
	if (scanf("%lf", &cap) != 1 || cap < 0.0) {
		printf("Invalid capacity.\n");
		return 1;
	}

	a = (Item *)malloc((size_t)n * sizeof(Item));
	if (!a) {
		printf("Memory allocation failed.\n");
		return 1;
	}

	printf("Enter weight and profit for each item:\n");
	for (i = 0; i < n; i++) {
		double w, p;
		printf("Item %d (w p): ", i + 1);
		if (scanf("%lf %lf", &w, &p) != 2 || w <= 0.0) {
			printf("Invalid input. Weight must be > 0.\n");
			free(a);
			return 1;
		}
		a[i].id = i + 1;
		a[i].w = w;
		a[i].p = p;
		a[i].r = p / w;
	}

	sortByRatioDesc(a, n);

	printf("\nSelected items (possibly fractional):\n");
	printf("ID\tTaken\tWeightUsed\tProfitGained\n");
	for (i = 0; i < n && cap > 0.0; i++) {
		if (a[i].w <= cap) {
			cap -= a[i].w;
			total += a[i].p;
			printf("%d\t1.0000\t%.4f\t\t%.4f\n", a[i].id, a[i].w, a[i].p);
		} else {
			double frac = cap / a[i].w;
			double gain = frac * a[i].p;
			total += gain;
			printf("%d\t%.4f\t%.4f\t\t%.4f\n", a[i].id, frac, cap, gain);
			cap = 0.0;
		}
	}

	printf("\nMaximum profit = %.4f\n", total);

	free(a);
	return 0;
}

/*
Complexity & classification:
- Problem type: optimization (greedy)
- Class: P (polynomial-time) for fractional knapsack
- Time: O(n^2) as written (bubble sort by profit/weight ratio) + O(n) selection
- Space: O(n)
- Notes: With an efficient sort, time becomes O(n log n).
*/
