#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	size;
	int	*array;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	array = (int *)malloc(sizeof(int) * size);
	if (array == NULL)
	{
		*range = NULL;
		return (-1);
	}
	i = 0;
	while (i < size)
	{
		array[i] = min + i;
		i++;
	}
	*range = array;
	return (size);
}
