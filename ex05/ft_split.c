#include <stdlib.h>

int		is_sep(char *charset, char c);

int		word_count(char *str, char *charset);

int		word_length(char *str, char *charset);

char	**ft_split(char *str, char *sep)
{
	char	**ret;
	int		words;
	int		i;
	int		j;

	words = word_count(str, sep);
	i = 0;
	ret = (char **)malloc((words + 1) * sizeof(char *));
	if (ret == NULL)
		return (NULL);
	while (i < words)
	{
		ret[i] = (char *)malloc((word_length(str, sep) + 1) * sizeof(char));
		if (ret[i] == NULL)
			return (NULL);
		j = 0;
		while (is_sep(sep, *str))
			str++;
		while (*str && !(is_sep(sep, *str)))
			ret[i][j++] = *str++;
		ret[i][j] = '\0';
		i++;
	}
	ret[i] = 0;
	return (ret);
}

int	is_sep(char *charset, char c)
{
	while (*charset)
	{
		if (*charset == c)
			return (1);
		charset++;
	}
	return (0);
}

int	word_count(char *str, char *charset)
{
	int	ret_count;

	ret_count = 0;
	while (*str)
	{
		while (*str && (is_sep(charset, *str)))
			str++;
		if (*str && !(is_sep(charset, *str)))
		{
			ret_count++;
			while (*str && !(is_sep(charset, *str)))
				str++;
		}
	}
	return (ret_count);
}

int	word_length(char *str, char *charset)
{
	int	ret_count;

	ret_count = 0;
	while (is_sep(charset, *str))
		str++;
	while (*str && !(is_sep(charset, *str)))
	{
		str++;
		ret_count++;
	}
	return (ret_count);
}
