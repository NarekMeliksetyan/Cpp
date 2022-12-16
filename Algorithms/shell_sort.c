/*
 * Сортировка Шелла
 * Shell sort
 */

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shell_sort(int *arr, int n)
{
    for (int step = n / 2; step > 0; step /= 2)
        for (int i = step; i < n; i++)
            for (int j = i - step; j >= 0 && arr[j] > arr[j + step]; j -= step)
                swap(&arr[j], &arr[j + step]);
}
