#include "cmp.h"

int fdf_array_min(int array[], size_t len)
{
    size_t i;
    int min;

    if (!array || !len)
        return (0);
    i = 0;
    min = array[0];
    while (i < len)
    {
        if (min > array[i])
            min = array[i];
        i++;
    }
    return (min);

}

int fdf_array_max(int array[], size_t len)
{
    size_t i;
    int max;

    if (!array || !len)
        return (0);
    i = 0;
    max = array[0];
    while (i < len)
    {
        if (max < array[i])
            max = array[i];
        i++;
    }
    return (max);
}

int fdf_abs(int x)
{
    if (x < 0)
        return (-x);
    else
        return (+x);
}
