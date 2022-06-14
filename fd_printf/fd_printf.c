/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:02:41 by fdrudi            #+#    #+#             */
/*   Updated: 2022/02/09 17:37:13 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fd_printf.h"

int	ft_assign(int fd, const char *str, int j, va_list args)
{
	int	len;

	len = 0;
	if (str[j] == 'c')
		len = fd_putchar((char)va_arg(args, int), fd);
	else if (str[j] == 's')
		len = fd_putstr(va_arg(args, char *), fd);
	else if (str[j] == 'p')
		len = fd_point_putnbr(va_arg(args, unsigned long), "0123456789abcdef", fd);
	else if (str[j] == 'd' || str[j] == 'i')
		len = fd_putnbr(va_arg(args, int), fd);
	else if (str[j] == 'u')
		len = fd_unsigned_putnbr(va_arg(args, unsigned int), fd);
	else if (str[j] == 'x')
		len = fd_hex_putnbr(va_arg(args, unsigned int), "0123456789abcdef", fd);
	else if (str[j] == 'X')
		len = fd_hex_putnbr(va_arg(args, unsigned int), "0123456789ABCDEF", fd);
	else if (str[j] == '%')
		len = fd_putchar('%', fd);
	return (len);
}

int	fd_printf(int fd, const char *str, ...)
{
	int		j;
	int		len;
	va_list	args;

	j = 0;
	len = 0;
	if (!str)
		return (0);
	va_start(args, str);
	while (str[j] != '\0')
	{
		if (str[j] == '%')
		{
			len += ft_assign(fd, str, j + 1, args);
			j++;
		}
		else
			len += fd_putchar(str[j], fd);
		j++;
	}
	va_end(args);
	return (len);
}
