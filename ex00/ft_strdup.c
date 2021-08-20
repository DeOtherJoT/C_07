#include <stdlib.h>

int	str_len(char *str);

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	dest = (char *)malloc((str_len(src) + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	str_len(char *src)
{
	int	c;

	c = 0;
	while (src[c])
	{
		c++;
	}
	return (c);
}
