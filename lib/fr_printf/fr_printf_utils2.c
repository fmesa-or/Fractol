/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:50:33 by fmesa-or          #+#    #+#             */
/*   Updated: 2024/04/23 20:37:02 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fr_printf.h"

int	ft_puthex_min(unsigned long n, int tempnb, int i)
{
	if (n > 15)
	{
		tempnb = ft_puthex_min(n / 16, 0, 0);
		if (tempnb == -1)
			return (-1);
		i += tempnb;
		n = n % 16;
	}
	if (n < 10)
	{
		n += 48;
		if (write(2, &n, 1) == -1)
			return (-1);
		i++;
	}
	else if (n < 16)
	{
		n += 87;
		if (write(2, &n, 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_puthex_mayus(unsigned long nb, int tempnb, int i)
{
	if (nb > 15)
	{
		tempnb = ft_puthex_mayus(nb / 16, 0, 0);
		if (tempnb == -1)
			return (-1);
		i += tempnb;
		nb = nb % 16;
	}
	if (nb < 10)
	{
		nb += 48;
		if (write(2, &nb, 1) == -1)
			return (-1);
		i++;
	}
	else if (nb < 16)
	{
		nb += 55;
		if (write(2, &nb, 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_putptr_hex(unsigned long nb)
{
	int	i;
	int	tempnb;

	i = 2;
	if (write (2, "0x", 2) == -1)
		return (-1);
	tempnb = ft_puthex_min(nb, 0, 0);
	if (tempnb == -1)
		return (-1);
	i += tempnb;
	return (i);
}
