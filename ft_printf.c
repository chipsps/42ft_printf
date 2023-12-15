/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchi <pchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:06:34 by pchi              #+#    #+#             */
/*   Updated: 2023/12/12 19:55:29 by pchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_formatprint(char c, va_list ap)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (c == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (c == 'd' || c == 'i')
		count += ft_printdigits((long)va_arg(ap, int), 10, 0);
	else if (c == 'u')
		count += ft_printdigits((long)va_arg(ap, unsigned int), 10, 0);
	else if (c == 'x')
		count += ft_printdigits((long)va_arg(ap, unsigned int), 16, 0);
	else if (c == 'X')
		count += ft_printdigits((long)va_arg(ap, unsigned int), 16, 1);
	else if (c == 'p')
		count += ft_putptr(va_arg(ap, void *));
	else
		count += ft_putchar(c);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	size_t	count;
	va_list	ap;

	if (!str)
		return (-1);
	count = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str != '%')
			count += ft_putchar(*str);
		else
			count += ft_formatprint(*(++str), ap);
		++str;
	}
	va_end(ap);
	return (count);
}
