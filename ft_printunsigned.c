/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 23:26:11 by abali             #+#    #+#             */
/*   Updated: 2023/01/25 23:26:26 by abali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int static	get_size(unsigned long int n)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		return (1);
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

int	ft_printunsigned(unsigned long int n)
{
	int					count;
	unsigned long int	dummy;

	dummy = n;
	count = 0;
	if (n > 9)
	{
		ft_printunsigned(n / 10);
		ft_printunsigned(n % 10);
	}
	else
	{
		ft_printchar(n % 10 + 48);
	}
	count = get_size(dummy);
	return (count);
}
