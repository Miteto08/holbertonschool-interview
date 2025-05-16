#include "sort.h"

/**
 * merge - Merge two subarrays of array[]
 * @array: Array to be sorted
 * @left: Left subarray
 * @right: Right subarray
 * @size: Size of the array
 * @mid: Middle index
 */
void merge(int *array, int *left, int *right, size_t size, size_t mid)
{
    size_t i = 0, j = 0, k = 0;
    size_t left_size = mid;
    size_t right_size = size - mid;

    printf("Merging...\n");
    printf("[left]: ");
    print_array(left, left_size);
    printf("[right]: ");
    print_array(right, right_size);

    while (i < left_size && j < right_size)
    {
        if (left[i] <= right[j])
            array[k++] = left[i++];
        else
            array[k++] = right[j++];
    }

    while (i < left_size)
        array[k++] = left[i++];

    while (j < right_size)
        array[k++] = right[j++];

    printf("[Done]: ");
    print_array(array, size);
}

/**
 * merge_sort_recursive - Recursive function for merge sort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void merge_sort_recursive(int *array, size_t size)
{
    size_t mid;
    int *left, *right;

    if (size < 2)
        return;

    mid = size / 2;
    left = malloc(mid * sizeof(int));
    right = malloc((size - mid) * sizeof(int));

    if (!left || !right)
    {
        free(left);
        free(right);
        return;
    }

    for (size_t i = 0; i < mid; i++)
        left[i] = array[i];
    for (size_t i = mid; i < size; i++)
        right[i - mid] = array[i];

    merge_sort_recursive(left, mid);
    merge_sort_recursive(right, size - mid);
    merge(array, left, right, size, mid);

    free(left);
    free(right);
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 * using the Merge sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    merge_sort_recursive(array, size);
}
