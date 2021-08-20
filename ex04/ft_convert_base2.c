int	verify_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = 1;
		if (base[i] <= ' ' || base[i] > '~')
			return (0);
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[i + j])
		{
			if (base[i] == base[i + j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	is_white_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v')
		return (1);
	if (c == '\r' || c == '\f')
		return (1);
	return (0);
}

int	ret_unique_char(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	calc_total_len(int nb, int radix)
{
	int	ret_val;

	if (nb <= 0)
		ret_val = 1;
	else
		ret_val = 0;
	while (nb)
	{
		nb /= radix;
		ret_val++;
	}
	return (ret_val);
}
