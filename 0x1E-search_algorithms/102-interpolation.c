#include "search_algos.h"

/**
 * interpolation_search - Searches for a value in a sorted array
 *                        of integers using interpolation search.
 * @array: A pointer to the first element of the array to search.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: If the value is not present or the array is NULL, -1.
 *         Otherwise, the first index where the value is located.
 *
 * Description: Prints a value every time it is compared in the array.
 */
int interpolation_search(int *array, size_t size, int value)
{
    size_t i, l, r;

    if (array == NULL)
        return (-1);

    for (l = 0, r = size - 1; r >= l;)
    {
        /* Calculate the probe index using interpolation formula */
        i = l + (((double)(r - l) / (array[r] - array[l])) * (value - array[l]));

        /* Check if the probe index is within the array bounds */
        if (i < size)
            printf("Value checked array[%ld] = [%d]\n", i, array[i]);
        else
        {
            printf("Value checked array[%ld] is out of range\n", i);
            break;
        }

        /* Check if the value is found at the probe index */
        if (array[i] == value)
            return (i);

        /* Update the search range based on the comparison result */
        if (array[i] > value)
            r = i - 1;
        else
            l = i + 1;
    }

    /* Value not found in the array */
    return (-1);
}
