#include <stdio.h>

void quick_sort(int *a, int n)
{
	int i, j, p, tmp;
	if (n < 2)  return;

	p = a[n / 2];   // Get the middle element as pivot ..

	for (i = 0, j = n - 1;; i++, j--) {
		while (a[i] < p)
			i++;
		while (p < a[j])
			j--;
		if (i >= j)
			break;
		tmp = a[i]; a[i] = a[j]; a[j] = tmp;    
	}

	quick_sort(a, i);
	quick_sort(a + i, n - i);
}


int main(void)
{
	int a[] = { 2, 5, 7, 3, -1, 1, 4 };
	int n = sizeof a / sizeof a[0];
	int i;
	for (i = 0; i < n; i++)
		printf("%d%s", a[i], i == n - 1 ? "\n" : " ");
	quick_sort(a, n);
	for (i = 0; i < n; i++)
		printf("%d%s", a[i], i == n - 1 ? "\n" : " ");

	return 0;
}