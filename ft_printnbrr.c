/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbrr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 23:04:45 by abali             #+#    #+#             */
/*   Updated: 2023/01/25 23:04:57 by abali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int static	get_size(int n)
{
	int	count;

	if (n == -2147483648)
		count = 11;
	else if (n <= 0)
	{
		count = 1;
		n = n * -1;
	}
	else
		count = 0;
	while (n > 0)
	{
		n = n / 10;
		count = count + 1;
	}
	return (count);
}

int
	ft_printnbrr(int n)
{
	int	count;
	int	dummy;

	dummy = n;
	count = 0;
	if (dummy == -2147483648)
		ft_printstrr("-2147483648");
	else if (dummy < 0)
	{
		ft_printchar('-');
		dummy = dummy * -1;
		ft_printnbrr(dummy);
	}
	else if (dummy > 9)
	{
		ft_printnbrr(dummy / 10);
		ft_printnbrr(dummy % 10);
	}
	else
	{
		ft_printchar(dummy % 10 + 48);
	}
	count = get_size(n);
	return (count);
}
