/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchi <pchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:13:37 by pchi              #+#    #+#             */
/*   Updated: 2023/12/12 21:05:51 by pchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putstr(char *str)
{
	if (!str)
		return (ft_putstr("(null)"));
	return (write(1, str, ft_strlen(str)));
}

int	ft_printdigits(long n, int base, int b)
{
	int		count;
	char	*symbols;

	count = 0;
	if (b == 1)
		symbols = "0123456789ABCDEF";
	else
		symbols = "0123456789abcdef";
	if (n < 0)
		return (ft_putchar('-') + ft_printdigits(-n, base, b));
	else if (n < base)
		return (ft_putchar(symbols[n]));
	else
	{
		count = ft_printdigits(n / base, base, b);
		return (count + ft_printdigits(n % base, base, b));
	}
}

int	ft_puthexa(unsigned long nb)
{
	char	*s;
	int		count;

	s = "0123456789abcdef";
	if (nb < 0)
		return (ft_putchar('-') + ft_puthexa(-nb));
	else if (nb < 16)
		return (ft_putchar(s[nb]));
	else
	{
		count = ft_puthexa(nb / 16);
		return (count + ft_putchar(s[nb % 16]));
	}
}

int	ft_putptr(void *ptr)
{
	if (ptr == 0)
		return (ft_putstr("(nil)"));
	return (ft_putstr("0x") + ft_puthexa((unsigned long)ptr));
}
