/*
 * Сортировка кучей
 * Heap sort
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(int arr[], int n, int i)
{
	int lrg = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && arr[l] > arr[lrg])
		lrg = l;
	if (r < n && arr[r] > arr[lrg])
		lrg = r;
	if (lrg != i)
	{
		swap(&arr[i], &arr[lrg]);
		heapify(arr, n, lrg);
	}
}

void heap_sort(int *arr, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	for (int i = n - 1; i > 0; i--)
	{
		swap(&arr[0], &arr[i]);
		heapify(arr, i, 0);
	}
}
