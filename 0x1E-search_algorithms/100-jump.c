#include "search_algos.h"
#include <math.h>

/**
 * jump_search - Searches for a value in a sorted array of integers using
 * the Jump search algorithm.
 * @array: Pointer to the first element of the array
 * @size: Number of elements in array
 * @value: Value to search for
 *
 * Return: The index where value is located, otherwise -1
 */
int jump_search(int *array, size_t size, int value)
{
	size_t i, jump, step;

	if (array == NULL || size == 0)
	{
		return (-1);
	}

	step = sqrt(size);
	i = jump = 0;

	while (jump < size && array[jump] < value)
	{
		printf("Value checked array[%ld] = [%d]\n", jump, array[jump]);
		i = jump;
		jump += step;
	}

	printf("Value found between indexes [%ld] and [%ld]\n", i, jump);
	jump = jump < size ? jump : size - 1;

	/* Find the exact position of the value */
	while (i < jump && array[i] < value)
	{
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
		i++;
	}

	printf("Value checked array[%ld] = [%d]\n", i, array[i]);
	return (array[i] == value ? (int) i : -1);
}
