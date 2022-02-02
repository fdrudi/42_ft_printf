/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_itoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:54:33 by fdrudi            #+#    #+#             */
/*   Updated: 2022/02/01 19:54:33 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_hex_intlen(unsigned int n)
{
	int	i;

	i = 0;
	while ((n / 16) >= 0)
	{
		i++;
	}
	return (i);
}

char	*ft_hex_itoa(unsigned int n, char *base)
{
	int		i;
	int		len;
	int		len2;
	char	*dest;

	i = 0;
	len = ft_hex_intlen(n);
	len2 = len;
	dest = (char *) malloc (sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	while (len)
	{
		dest[len] = base[((n / 16) % 16)];
		len--;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
