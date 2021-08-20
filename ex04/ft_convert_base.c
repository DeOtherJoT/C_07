#include <stdlib.h>

int		verify_base(char *base);

int		str_len(char *str);

int		is_white_space(char c);

int		ret_unique_char(char *base_from, char c);

int		calc_total_len(int nb, int radix);

int		atoi_base(char *nbr, char *base_from);

void	putnbr_base(int nbr, char *base_to, int numb_len, char *ptr);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		num_10;
	char	*ret_ptr;
	int		total_numb_len;

	if (!verify_base(base_from) || !verify_base(base_to))
		return (NULL);
	num_10 = atoi_base(nbr, base_from);
	total_numb_len = calc_total_len(num_10, str_len(base_to));
	ret_ptr = (char *)malloc((total_numb_len + 1) * sizeof(char));
	if (ret_ptr == NULL)
		return (NULL);
	putnbr_base(num_10, base_to, total_numb_len, ret_ptr);
	return (ret_ptr);
}

int	atoi_base(char *nbr, char *base_from)
{
	int	neg;
	int	res;
	int	radix;

	radix = str_len(base_from);
	res = 0;
	neg = 1;
	while (is_white_space(*nbr))
		nbr++;
	while (*nbr == '+' || *nbr == '-')
	{
		if (*nbr == '-')
			neg *= -1;
		nbr++;
	}
	while (ret_unique_char(base_from, *nbr) != -1)
	{
		res *= radix;
		res += ret_unique_char(base_from, *nbr);
		nbr++;
	}
	return (res * neg);
}

void	putnbr_base(int nbr, char *base_to, int numb_len, char *ptr)
{
	int				radix;
	int				loop_ctrl;
	int				index_ctrl;
	unsigned int	nb;

	radix = str_len(base_to);
	if (nbr < 0)
	{
		ptr[0] = '-';
		loop_ctrl = 1;
		index_ctrl = 0;
		nb = nbr * -1;
	}
	else
	{
		loop_ctrl = 0;
		index_ctrl = 1;
		nb = nbr;
	}
	while (loop_ctrl < numb_len)
	{
		ptr[numb_len - index_ctrl - loop_ctrl++] = base_to[nb % radix];
		nb /= radix;
	}
	ptr[numb_len] = '\0';
}
