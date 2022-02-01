/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:17:06 by fdrudi            #+#    #+#             */
/*   Updated: 2022/01/25 16:17:06 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	if (s == NULL)
		return ;
	while (*s != '\0')
	{
		write(1, &*s, 1);
		s++;
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*united;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = (char *) malloc (sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	united = (char *) malloc (sizeof(char)
			* (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (united == NULL)
		return (NULL);
	while (s1[j] != '\0')
		united[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		united[i++] = s2[j++];
	united[i] = '\0';
	free (s1);
	return (united);
}

static int	ft_intlen(int n)
{
	int	i;

	i = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static int	ft_div(int len)
{
	int	div;

	div = 1;
	if (len == 1)
		return (1);
	while (len > 1)
	{
		div *= 10;
		len--;
	}
	return (div);
}

static void	ft_neg(int *n, char *dest, int *i, int *len)
{
	if (*n == -2147483648)
	{
		*n = 147483648;
		dest[0] = '-';
		dest[1] = '2';
		*i += 2;
		*len -= 2;
	}
	if (*n < 0)
	{
		*n *= -1;
		dest[0] = '-';
		*i += 1;
		*len -= 1;
	}
}

char	*ft_itoa(int n)
{
	int		i;
	int		len;
	int		len2;
	char	*dest;

	i = 0;
	len = ft_intlen(n);
	len2 = len;
	dest = (char *) malloc (sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	if (n == -2147483648 || n < 0)
		ft_neg(&n, dest, &i, &len);
	while (i < len2)
	{
		dest[i] = ((n / ft_div(len)) % 10) + 48;
		len--;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}


static int	ft_unsigned_intlen(unsigned int n)
{
	int	i;

	i = 1;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static unsigned int	ft_unsigned_div(unsigned int len)
{
	int	div;

	div = 1;
	if (len == 1)
		return (1);
	while (len > 1)
	{
		div *= 10;
		len--;
	}
	return (div);
}

char	*ft_unsigned_itoa(unsigned int n)
{
	int		i;
	int		len;
	int		len2;
	char	*dest;

	i = 0;
	len = ft_unsigned_intlen(n);
	len2 = len;
	dest = (char *) malloc (sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	while (i < len2)
	{
		dest[i] = ((n / ft_unsigned_div(len)) % 10) + 48;
		len--;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}


char	*ft_assign(const char *str, int j, va_list args)
{
	char	*dst;

	if (str[j] == 'c')
	{
		dst = (char *) malloc (sizeof(char) * 2);
		dst[0] = (char)va_arg(args, int);
		dst[1] = '\0';
	}
	else if (str[j] == 's')
		dst = va_arg(args, char *);
	//else if (str[j] == 'p')
		//void pointer address in hexadecimal
	else if (str[j] == 'd' || str[j] == 'i')
		dst = ft_itoa(va_arg(args, int));
	else if (str[j] == 'u')
		dst = ft_unsigned_itoa(va_arg(args, unsigned int));
	//else if (str[j] == 'x')
		//hexadecimal number in lowercase format
	//else if (str[j] == 'X')
		//hexadedimal numbers in uppercase format
	else if (str[j] == '%')
	{
		dst = (char *) malloc (sizeof(char) * 2);
		dst[0] = '%';
		dst[1] = '\0';
	}

	return (dst);
}

int	ft_printf(const char *str, ...)
{
	int	j;
	int	i;
	va_list	args;
	char *dst;
	char *tmp;

	j = 0;
	i = 0;
	dst = (char *) malloc (ft_strlen(str) + 1);
	if (!dst)
		return (0);
	va_start(args, str);
	while (str[j] != '\0')
	{
		if (str[j] == '%')
		{
			tmp = ft_assign(str, j+1, args);
			//ft_putstr(tmp);
			dst = ft_strjoin_gnl(dst, tmp);
			j++;
			i = ft_strlen(dst) - 1;
		}
		else
			dst[i] = str[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	ft_putstr(dst);
	va_end(args);
	return (ft_strlen(dst));
}

int	main()
{
	const char	*str = "abcde";
	char ch;
	int	num = 123;
	unsigned int un = -1;

	ch = 'a';
	ft_printf("stampami :\n %i\n %%\n %c\n %s\n %c\n %u\n", num, ch, str, ch, un);
	printf("Printf : %u\n", un);
	ft_printf("My Printf : %u", un);
	return (0);
}
