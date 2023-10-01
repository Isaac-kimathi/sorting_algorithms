#include "sort.h"

/**
 * merge_subarr - Sort a subarray of integers.
 * @subarr: A subarray of an array of integers to sort.
 * @buffer: A buffer to store the sorted subarray.
 * @bgg: The front index of the array.
 * @kat: The middle index of the array.
 * @rear: The back index of the array.
 */
void merge_subarr(int *subarr, int *buffer, size_t bgg, size_t kat,
				size_t rear)
{
	size_t x, y, z = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + bgg, kat - bgg);
	printf("[right]: ");
	print_array(subarr + kat, rear - kat);

	for (x = bgg, y = kat; z < kat && y < rear; z++)
		buffer[z] = (subarr[x] < subarr[y]) ? subarr[x++] : subarr[y++];
	for (; x < kat; x++)
		buffer[z++] = subarr[x];
	for (; y < rear; y++)
		buffer[z++] = subarr[y];
	for (x = bgg, z = 0; x < rear; x++)
		subarr[x] = buffer[z++];

	printf("[Done]: ");
	print_array(subarr + bgg, rear - bgg);
}

/**
 * merge_sort_recursive - Implement the merge sort algorithm through recursion.
 * @subarr: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted result.
 * @front: The front index of the subarray.
 * @rear: The back index of the subarray.
 */
void merge_sort_recursive(int *subarr, int *buffer, size_t bgg, size_t rear)
{
	size_t kat;

	if (rear - bgg > 1)
	{
		kat = bgg + (rear - bgg) / 2;
		merge_sort_recursive(subarr, buffer, bgg, kat);
		merge_sort_recursive(subarr, buffer, kat, rear);
		merge_subarr(subarr, buffer, bgg, kat, rear);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 * order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	merge_sort_recursive(array, buffer, 0, size);

	free(buffer);
}
