/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:02:41 by fdrudi            #+#    #+#             */
/*   Updated: 2022/02/02 18:02:41 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_assign(const char *str, int j, va_list args)
{
	int	print_len;

	print_len = 0;
	if (str[j] == 'c')
		print_len = ft_putchar((char)va_arg(args, int));
	else if (str[j] == 's')
		print_len = ft_putstr(va_arg(args, char *));
	else if (str[j] == 'p')
		print_len = ft_point_putnbr(va_arg(args, unsigned long), "0123456789abcdef");
	else if (str[j] == 'd' || str[j] == 'i')
		print_len = ft_putnbr(va_arg(args, int));
	else if (str[j] == 'u')
		print_len = ft_unsigned_putnbr(va_arg(args, unsigned int));
	else if (str[j] == 'x')
		print_len = ft_hex_putnbr(va_arg(args, unsigned int), "0123456789abcdef");
	else if (str[j] == 'X')
		print_len = ft_hex_putnbr(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (str[j] == '%')
		print_len = ft_putchar('%');
	return (print_len);
}

int	ft_printf(const char *str, ...)
{
	int	j;
	int	len;
	va_list	args;

	j = 0;
	len = 0;
	va_start(args, str);
	while (str[j] != '\0')
	{
		if (str[j] == '%')
		{
			len += ft_assign(str, j+1, args);
			j++;
		}
		else
			len += ft_putchar(str[j]);
		j++;
	}
	va_end(args);
	return (len);
}

/*int	main()
{
	const char	*str = "abcde";
	char ch;
	int	num = 123;
	unsigned int un = -1456;
	int i = 0;

	ch = 'a';
	//ft_printf("mine : %p\n", str);
	//i = printf("real : %p\n", str);
	ft_printf("stampami :\n %p\n %i\n %d\n %c\n %s\n %x\n %X\n %u\n", str, num, num, ch, str, un, un, un);
	i = printf("stampami :\n %p\n %i\n %d\n %c\n %s\n %x\n %X\n %u\n", str, num, num, ch, str, un, un, un);
	printf("\nreal len : %d", i);
	//ft_printf("My Printf : %p\n", str);
	return (0);
}*/
