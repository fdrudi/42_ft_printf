/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:33:32 by fdrudi            #+#    #+#             */
/*   Updated: 2022/02/02 19:33:32 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_putnbr(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 10)
	{
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	else
	{
		i += ft_putchar(48 + n);
	}
	return (i);
}

int	ft_hex_putnbr(unsigned int n, char *hex)
{
	int	i;

	i = 0;
	if (n >= 16)
		i += ft_hex_putnbr((n / 16), hex);
	i += ft_putchar(hex[(n % 16)]);
	return (i);
}

int	ft_point_print(unsigned long n, char *hex)
{
	int	i;

	i = 0;
	if (n >= 16)
		i += ft_point_print((n / 16), hex);
	i += ft_putchar(hex[(n % 16)]);
	return (i);
}

int	ft_point_putnbr(unsigned long n, char *hex)
{
	int	i;

	i = 2;
	ft_putchar('0');
	ft_putchar('x');
	i += ft_point_print(n, hex);
	return (i);
}
