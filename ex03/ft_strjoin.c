#include <stdlib.h>

int		ret_str_len(char *str);

int		ret_total_len(int size, char **strs, char *sep);

char	*str_concat(char *dest, char *src);

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*ret_ptr;
	char	*array;
	int		index;

	if (size == 0)
	{
		array = (char *)malloc(sizeof(char));
		*array = '\0';
		return (array);
	}
	array = (char *)malloc(ret_total_len(size, strs, sep) * sizeof(char));
	if (array == NULL)
		return (NULL);
	ret_ptr = array;
	index = 0;
	while (index < size)
	{
		array = str_concat(array, strs[index]);
		if (index < size - 1)
			array = str_concat(array, sep);
		index++;
	}
	*array = '\0';
	return (ret_ptr);
}

int	ret_str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ret_total_len(int size, char **strs, char *sep)
{
	int	i;
	int	ret_val;
	int	sep_len;

	sep_len = ret_str_len(sep);
	i = 0;
	ret_val = 1;
	while (i < size)
	{
		ret_val += ret_str_len(strs[i]);
		if (i < size - 1)
			ret_val += sep_len;
		i++;
	}
	return (ret_val);
}

char	*str_concat(char *dest, char *src)
{
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	return (dest);
}
