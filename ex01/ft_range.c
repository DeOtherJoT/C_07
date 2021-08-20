#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*ret_ptr;
	int	size;
	int	i;

	if (min >= max)
		return (NULL);
	size = max - min;
	i = 0;
	ret_ptr = (int *)malloc(sizeof(int) * size);
	if (ret_ptr == NULL)
		return (NULL);
	while (i < size)
	{
		*(ret_ptr + i) = min + i;
		i++;
	}
	return (ret_ptr);
}
