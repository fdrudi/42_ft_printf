/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_printf_num_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:33:32 by fdrudi            #+#    #+#             */
/*   Updated: 2022/02/02 19:33:32 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fd_printf.h"

int	fd_unsigned_putnbr(unsigned int n, int fd)
{
	int	i;

	i = 0;
	if (n >= 10)
	{
		i += fd_putnbr(n / 10, fd);
		i += fd_putnbr(n % 10, fd);
	}
	else
	{
		i += fd_putchar(48 + n, fd);
	}
	return (i);
}

int	fd_hex_putnbr(unsigned int n, char *hex, int fd)
{
	int	i;

	i = 0;
	if (n >= 16)
		i += fd_hex_putnbr((n / 16), hex, fd);
	i += fd_putchar(hex[(n % 16)], fd);
	return (i);
}

int	fd_point_print(unsigned long n, char *hex, int fd)
{
	int	i;

	i = 0;
	if (n >= 16)
		i += fd_point_print((n / 16), hex, fd);
	i += fd_putchar(hex[(n % 16)], fd);
	return (i);
}

int	fd_point_putnbr(unsigned long n, char *hex, int fd)
{
	int	i;

	i = 2;
	fd_putchar('0', fd);
	fd_putchar('x', fd);
	i += fd_point_print(n, hex, fd);
	return (i);
}
