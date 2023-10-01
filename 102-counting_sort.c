#include "sort.h"

/**
 * max_int - finds the maximum value in an array of integers
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum int in the array.
 */
int max_int(int *array, int size)
{
	int x, max;

	for (max = array[0], x = 1; x < size; x++)
	{
		if (array[x] > max)
			max = array[x];
	}

	return (max);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 * using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *occurence, *arranged, max, x;

	if (array == NULL || size < 2)
		return;

	arranged = malloc(sizeof(int) * size);
	if (arranged == NULL)
		return;
	max = max_int(array, size);
	occurence = malloc(sizeof(int) * (max + 1));
	if (occurence == NULL)
	{
		free(arranged);
		return;
	}
	for (x = 0; x < (max + 1); x++)
		occurence[x] = 0;
	for (x = 0; x < (int)size; x++)
		occurence[array[x]] += 1;
	for (x = 0; x < (max + 1); x++)
		occurence[x] += occurence[x - 1];
	print_array(occurence, max + 1);

	for (x = 0; x < (int)size; x++)
	{
		arranged[occurence[array[x]] - 1] = array[x];
		occurence[array[x]] -= 1;
	}
	for (x = 0; x < (int)size; x++)
		array[x] = arranged[x];

	free(arranged);
	free(occurence);
}
