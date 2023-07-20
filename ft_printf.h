/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:23:44 by abali             #+#    #+#             */
/*   Updated: 2023/01/25 22:26:11 by abali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int		ft_printchar(int c);
int		ft_printstrr(char *str);
int		ft_printptrhex(unsigned long long ptr);
int		ft_printnbrr(int n);
int		ft_printunsigned(unsigned long int n);
int		ft_printnbrhex(unsigned long long n, char type);
int		ft_printf(const char *str, ...);

#endif
