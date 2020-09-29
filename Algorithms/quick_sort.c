/*
 * Быстрая сортировка
 * Qiuck sort
 */


void    swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


int     partition(int *arr, int low, int high)
{
    int i = low;
    int pivot = arr[high];

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[high]);

    return (i);
}


void    quick_sort(int *arr, int low, int high)
{
    if (low < high)
    {
        int m = partition(arr, low, high);
        quick_sort(arr, low, m - 1);
        quick_sort(arr, m + 1, high);
    }
}
