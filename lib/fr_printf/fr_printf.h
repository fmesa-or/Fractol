/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:10:37 by fmesa-or          #+#    #+#             */
/*   Updated: 2024/04/23 20:37:03 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FR_PRINTF_H
# define FR_PRINTF_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		fr_printf(char const *s, ...);
int		ft_putchar(char c);
int		ft_check_dani(const char *s);
int		ft_putstr(char *s);
int		ft_putnbr(long nb, int tempnb, int i);
int		ft_putnbr_u(unsigned int n);
int		ft_puthex_min(unsigned long n, int tempnb, int i);
int		ft_puthex_mayus(unsigned long nb, int tempnb, int i);
int		ft_putptr_hex(unsigned long nb);

#endif