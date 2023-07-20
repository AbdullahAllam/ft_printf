/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptrhex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:59:21 by abali             #+#    #+#             */
/*   Updated: 2023/01/26 16:00:11 by abali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printptrhex(unsigned long long ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
	{
		write(1, "0x0", 3);
		count = 3;
	}
	else
	{
		write(1, "0x", 2);
		count = 2 + ft_printnbrhex(ptr, 'x');
	}
	return (count);
}
