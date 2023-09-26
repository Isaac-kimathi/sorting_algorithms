#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * Description: Prints the array after each swap occurs
 * @array: An array of integers to sort
 * @size: The size of the array
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t x, y, sp;
	int chngd, tph;

	if (size < 2)
		return;

	sp = size;
	for (x = 0; x < sp - 1; x++)
	{
		chngd = 0;
		for (y = 0; y < sp - 1 - x; y++)
		{
			if (array[y] > array[y + 1])
			{
				tph = array[y];
				array[y] = array[y + 1];
				array[y + 1] = tph;
				print_array(array, size);
				chngd = 1;
			}
		}
		if (chngd == 0)
		{
			break;
		}
	}
}
