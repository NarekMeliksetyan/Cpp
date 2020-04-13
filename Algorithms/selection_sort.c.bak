/*
 * Сортировка выбором
 * Selection sort
 */

void	swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void	selection_sort(int *arr, int n)
{
	for (int i = 1; i < n; i++)
	{
		if (arr[i - 1] > arr[i])
		{
			swap(&arr[i - 1], &arr[i]);
			i = 0;
		}
	}
}
