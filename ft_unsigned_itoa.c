/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:23:24 by fdrudi            #+#    #+#             */
/*   Updated: 2022/02/01 19:23:24 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
