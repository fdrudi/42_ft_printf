/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point_itoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:29:56 by fdrudi            #+#    #+#             */
/*   Updated: 2022/02/02 16:29:56 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_point_intlen(unsigned long n)
{
	int	i;

	i = 0;
	while (n >= 16)
	{
		n = (n / 16);
		i++;
	}
	return (i);
}

static unsigned long	ft_point_div(unsigned long n, int len)
{
	while (len)
	{
		n = (n / 16);
		len--;
	}
	return (n);
}

char	*ft_point_itoa(unsigned long n, char *base)
{
	int		i;
	int		len;
	int		len2;
	char	*dest;

	len = ft_point_intlen(n);
	len2 = len + 2;
	dest = (char *) malloc (sizeof(char) * (len + 3));
	if (dest == NULL)
		return (NULL);
	dest[0] = '0';
	dest[1] = 'x';
	i = 2;
	while (i <= len2)
	{
		dest[i] = base[((ft_point_div(n, len)) % 16)];
		len--;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
