/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:18:45 by fmesa-or          #+#    #+#             */
/*   Updated: 2024/04/23 20:37:02 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fr_printf.h"

static int	ft_check_format(va_list vargs, char input)
{
	int	length;

	length = 0;
	if (input == 'c')
		length += ft_putchar(va_arg(vargs, int));
	else if (input == 's')
		length += ft_putstr(va_arg(vargs, char *));
	else if (input == 'p')
		length += ft_putptr_hex(va_arg(vargs, unsigned long));
	else if (input == 'd' || input == 'i')
		length += ft_putnbr(va_arg(vargs, int), 0, 0);
	else if (input == 'u')
		length += ft_putnbr_u(va_arg(vargs, unsigned int));
	else if (input == 'x')
		length += ft_puthex_min(va_arg(vargs, unsigned int), 0, 0);
	else if (input == 'X')
		length += ft_puthex_mayus(va_arg(vargs, unsigned int), 0, 0);
	return (length);
}

static int	ft_looper(va_list vargs, char const *input, int length)
{
	int	tempnb;

	while (*input)
	{
		if (*input == '%' && (*(input + 1)) != '%')
		{
			tempnb = ft_check_format(vargs, *(input + 1));
			if (tempnb == -1)
				return (-1);
			length += tempnb;
			input++;
		}
		else
		{
			if (write(2, input, 1) == -1)
				return (-1);
			length++;
			if (*input == '%')
				input++;
		}
		input++;
	}
	return (length);
}

int	fr_printf(char const *input, ...)
{
	va_list	vargs;
	int		length;

	length = 0;
	va_start(vargs, input);
	length = ft_looper(vargs, input, length);
	va_end(vargs);
	return (length);
}
/*
int	main(int argc, char *argv[])
{
	if (argc > 0)
	{
		ft_printf(argv[1], argv[2]);
	}
	return (0);
}*/