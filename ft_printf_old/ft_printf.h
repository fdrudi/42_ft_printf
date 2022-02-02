/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:38:51 by fdrudi            #+#    #+#             */
/*   Updated: 2022/02/02 17:38:51 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_printf(const char *str, ...);
char	*ft_assign(const char *str, int j, va_list args);
char	*ft_point_itoa(unsigned long n, char *base);
static unsigned long	ft_point_div(unsigned long n, int len);
static int	ft_point_intlen(unsigned long n);
char	*ft_hex_itoa(unsigned int n, char *base);
static unsigned int	ft_hex_div(unsigned int n, int len);
static int	ft_hex_intlen(unsigned int n);
char	*ft_unsigned_itoa(unsigned int n);
static unsigned int	ft_unsigned_div(unsigned int len);
static int	ft_unsigned_intlen(unsigned int n);
char	*ft_itoa(int n);
static void	ft_neg(int *n, char *dest, int *i, int *len);
static int	ft_div(int len);
static int	ft_intlen(int n);
char	*ft_strjoin_gnl(char *s1, char *s2);
size_t	ft_strlen(const char *s);
void	ft_putstr(char *s);
void	ft_putchar(char c);

#endif
