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

#include "ft_printf.h"

int	ft_assign(const char *str, int j, va_list args)
{
	int	len;

	len = 0;
	if (str[j] == 'c')
		len = ft_putchar((char)va_arg(args, int));
	else if (str[j] == 's')
		len = ft_putstr(va_arg(args, char *));
	else if (str[j] == 'p')
		len = ft_point_putnbr(va_arg(args, unsigned long), "0123456789abcdef");
	else if (str[j] == 'd' || str[j] == 'i')
		len = ft_putnbr(va_arg(args, int));
	else if (str[j] == 'u')
		len = ft_unsigned_putnbr(va_arg(args, unsigned int));
	else if (str[j] == 'x')
		len = ft_hex_putnbr(va_arg(args, unsigned int), "0123456789abcdef");
	else if (str[j] == 'X')
		len = ft_hex_putnbr(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (str[j] == '%')
		len = ft_putchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
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
			len += ft_assign(str, j + 1, args);
			j++;
		}
		else
			len += ft_putchar(str[j]);
		j++;
	}
	va_end(args);
	return (len);
}
