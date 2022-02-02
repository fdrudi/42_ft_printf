/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:36:10 by fdrudi            #+#    #+#             */
/*   Updated: 2022/02/02 19:36:10 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H


#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_printf(const char *str, ...);
int	ft_assign(const char *str, int j, va_list args);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int n);
int	ft_unsigned_putnbr(unsigned int n);
int	ft_hex_putnbr(unsigned int n, char *hex);
int	ft_point_print(unsigned long n, char *hex);
int	ft_point_putnbr(unsigned long n, char *hex);

#endif
