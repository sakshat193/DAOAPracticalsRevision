/* Relevant questions: PDF Q20/Q36/Q37 (B-Tree insertion variants) */
/* Also matches DAOA list items: 20, 36, 37 */
/* Full text: */
/* 20. Constructing B-tree with the insertion of elements to satisfy its properties.[^1] */
/* 36. Create a B-tree by inserting elements while ensuring that all B-tree properties are maintained.[^1] */
/* 37. Construct a B-tree through successive insertions of keys such that the structure always satisfies the rules of a B-tree.[^1] */

#include <stdio.h>
#include <stdlib.h>

typedef struct BNode {
	int *k;
	struct BNode **c;
	int n;
	int leaf;
} BNode;

static BNode *newNode(int t, int leaf)
{
	BNode *x = (BNode *)malloc(sizeof(BNode));
	if (!x) return NULL;
	x->k = (int *)malloc((size_t)(2 * t - 1) * sizeof(int));
	x->c = (BNode **)malloc((size_t)(2 * t) * sizeof(BNode *));
	if (!x->k || !x->c) {
		free(x->k);
		free(x->c);
		free(x);
		return NULL;
	}
	x->n = 0;
	x->leaf = leaf;
	int i;
	for (i = 0; i < 2 * t; i++) x->c[i] = NULL;
	return x;
}

static void splitChild(BNode *x, int i, BNode *y, int t)
{
	BNode *z = newNode(t, y->leaf);
	if (!z) {
		printf("Memory allocation failed.\n");
		exit(1);
	}

	z->n = t - 1;
	int j;
	for (j = 0; j < t - 1; j++) z->k[j] = y->k[j + t];
	if (!y->leaf) {
		for (j = 0; j < t; j++) z->c[j] = y->c[j + t];
	}
	y->n = t - 1;

	for (j = x->n; j >= i + 1; j--) x->c[j + 1] = x->c[j];
	x->c[i + 1] = z;

	for (j = x->n - 1; j >= i; j--) x->k[j + 1] = x->k[j];
	x->k[i] = y->k[t - 1];
	x->n++;
}

static void insertNonFull(BNode *x, int k, int t)
{
	int i = x->n - 1;
	if (x->leaf) {
		while (i >= 0 && k < x->k[i]) {
			x->k[i + 1] = x->k[i];
			i--;
		}
		x->k[i + 1] = k;
		x->n++;
		return;
	}

	while (i >= 0 && k < x->k[i]) i--;
	i++;

	if (x->c[i]->n == 2 * t - 1) {
		splitChild(x, i, x->c[i], t);
		if (k > x->k[i]) i++;
	}
	insertNonFull(x->c[i], k, t);
}

static BNode *insert(BNode *root, int k, int t)
{
	if (!root) {
		root = newNode(t, 1);
		if (!root) {
			printf("Memory allocation failed.\n");
			exit(1);
		}
		root->k[0] = k;
		root->n = 1;
		return root;
	}

	if (root->n == 2 * t - 1) {
		BNode *s = newNode(t, 0);
		if (!s) {
			printf("Memory allocation failed.\n");
			exit(1);
		}
		s->c[0] = root;
		splitChild(s, 0, root, t);
		int i = 0;
		if (k > s->k[0]) i = 1;
		insertNonFull(s->c[i], k, t);
		return s;
	}

	insertNonFull(root, k, t);
	return root;
}

static void printLevel(BNode *x, int level)
{
	if (!x) return;
	int i;
	printf("Level %d: ", level);
	for (i = 0; i < x->n; i++) printf("%d ", x->k[i]);
	printf("\n");
	if (!x->leaf) {
		for (i = 0; i <= x->n; i++) printLevel(x->c[i], level + 1);
	}
}

static void freeTree(BNode *x, int t)
{
	if (!x) return;
	if (!x->leaf) {
		int i;
		for (i = 0; i <= x->n; i++) freeTree(x->c[i], t);
	}
	free(x->k);
	free(x->c);
	free(x);
}

int main(void)
{
	int t, n, i;
	BNode *root = NULL;

	printf("Enter minimum degree t (>= 2): ");
	if (scanf("%d", &t) != 1 || t < 2) {
		printf("Invalid t.\n");
		return 1;
	}
	printf("Enter number of keys to insert: ");
	if (scanf("%d", &n) != 1 || n < 0) {
		printf("Invalid n.\n");
		return 1;
	}

	printf("Enter %d integer keys: ", n);
	for (i = 0; i < n; i++) {
		int k;
		if (scanf("%d", &k) != 1) {
			printf("Invalid input.\n");
			freeTree(root, t);
			return 1;
		}
		root = insert(root, k, t);
	}

	printf("\nB-Tree (preorder by levels):\n");
	printLevel(root, 0);

	freeTree(root, t);
	return 0;
}

/*
Complexity & classification:
- Problem type: balanced search tree operations (B-Tree insertion)
- Class: P (polynomial-time)
- Time: O(h * t) per insertion in this implementation, where h = height; typically O(t * log_t N)
- Space: O(N) nodes/keys stored
- Notes: Implements insertion with splitting (CLRS-style). Prints a simple traversal.
*/
