/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:02:47 by abali             #+#    #+#             */
/*   Updated: 2023/01/25 21:05:16 by abali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check(char a)
{
	char	*str;
	int		i;

	str = "cspdiuxX%";
	i = 0;
	while (str[i])
	{
		if (a == str[i])
			return (1);
		i++;
	}
	return (0);
}

static int	ft_decide(char a, va_list my_list)
{
	int	no_printed;

	no_printed = 0;
	if (a == 'c')
		no_printed = ft_printchar(va_arg(my_list, int));
	else if (a == 's')
		no_printed = ft_printstrr(va_arg(my_list, char *));
	else if (a == 'p')
		no_printed = ft_printptrhex(va_arg(my_list, unsigned long long));
	else if (a == 'd' || a == 'i')
		no_printed = ft_printnbrr(va_arg(my_list, int));
	else if (a == 'u')
		no_printed = ft_printunsigned(va_arg(my_list, unsigned int));
	else if (a == 'x' || a == 'X')
		no_printed = ft_printnbrhex(va_arg(my_list, unsigned int), a);
	else if (a == '%')
		no_printed = ft_printchar('%');
	return (no_printed);
}

int	ft_printf(const char *str, ...)
{
	va_list	my_list;
	int		i;
	int		no_printed;

	va_start(my_list, str);
	i = 0;
	no_printed = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (!ft_check(str[i + 1]) && str[i + 1] != ' ')
				return (-1);
			while (!ft_check(str[i + 1]) && str[i + 1] == ' ')
				i++;
			no_printed = no_printed + ft_decide(str[i + 1], my_list);
			i++;
		}
		else
			no_printed = no_printed + ft_printchar(str[i]);
		i++;
	}
	va_end(my_list);
	return (no_printed);
}
/*
#include <stdio.h>
int main()
{
	int	x;
	int y;
	
	y = printf("42%c42", 5);
	printf("%c", '\n');
	printf("%d\n",y);
	printf("%c", '\n');
	x = ft_printf("42%c42", 5);
	printf("%c", '\n');
	printf("%d\n",x);
	return (0);
}
*/