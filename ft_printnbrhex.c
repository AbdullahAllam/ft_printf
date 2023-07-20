/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbrhex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:49:17 by abali             #+#    #+#             */
/*   Updated: 2023/01/26 11:49:25 by abali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int
	arraysize(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int
	checkarray( char *base)
{
	int	i;
	int	j;

	i = 0;
	if (!base[i] || !base[i + 1])
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] < 32 || base[i] > 126)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int
	ft_putnbr_base(unsigned long long nbr, char *base)
{	
	int	size;
	int	i;
	int	numberarray[15];
	int	count;

	count = 0;
	size = arraysize(base);
	i = 0;
	if (nbr == 0)
		count = ft_printchar('0');
	if (checkarray(base))
	{
		while (nbr)
		{
			numberarray[i] = nbr % size;
			nbr = nbr / size;
			i++;
		}
		if (i == 0 && nbr != 0)
			count = count + ft_printchar(base[numberarray[i]]);
		while (--i >= 0)
			count = count + ft_printchar(base[numberarray[i]]);
	}
	return ((int)count);
}

int	ft_printnbrhex(unsigned long long n, char type)
{
	int	count;

	count = 0;
	if (type == 'X')
		count = ft_putnbr_base(n, "0123456789ABCDEF");
	else if (type == 'x')
		count = ft_putnbr_base(n, "0123456789abcdef");
	return (count);
}
