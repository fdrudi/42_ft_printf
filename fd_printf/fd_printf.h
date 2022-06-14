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

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	fd_printf(int fd, const char *str, ...);
int	ft_assign(int fd, const char *str, int j, va_list args);
int	fd_putchar(char c, int fd);
int	fd_putstr(char *s, int fd);
int	fd_putnbr(int n, int fd);
int	fd_unsigned_putnbr(unsigned int n, int fd);
int	fd_hex_putnbr(unsigned int n, char *hex, int fd);
int	fd_point_print(unsigned long n, char *hex, int fd);
int	fd_point_putnbr(unsigned long n, char *hex, int fd);

#endif
