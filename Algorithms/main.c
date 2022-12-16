#include <stdlib.h>
#include <stdio.h>

int *scan_array(int);
void print_array(int *, int);

void bubble_sort(int *, int);
void heap_sort(int *, int);
void insertion_sort(int *, int);
void quick_sort(int *, int, int);
void selection_sort(int *, int);
void shell_sort(int *, int);

int main()
{
    int n;
    int *arr;

    printf("Enter size of array: ");
    scanf("%d", &n);
    arr = scan_array(n);

    //
    //    Uncomment an algorithm to use:
    //
    //    bubble_sort(arr, n);
    heap_sort(arr, n);
    //    insertion_sort(arr, n);
    //    quick_sort(arr, 0, n);
    //    selection_sort(arr, n);
    //    shell_sort(arr, n);

    printf("\nSorted array:\n");
    print_array(arr, n);
    free(arr);
    arr = 0;
    return (0);
}

int *scan_array(int n)
{
    int *arr;
    arr = malloc(sizeof(int) * n);
    if (!arr)
        return (0);

    printf("Enter the elements of array:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    return (arr);
}

void print_array(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
