/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:43:42 by fmesa-or          #+#    #+#             */
/*   Updated: 2023/12/13 21:52:23 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Creates a string that represents the value of a integer given as argument.*/

#include "libft.h"

static int	ft_lennumber(long nb)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	if (nb > 9)
		i += ft_lennumber(nb / 10);
	i++;
	return (i);
}

static void	ft_itoanmbr(long nb, char *c, unsigned int lenn)
{
	unsigned int	i;
	unsigned int	neg;

	i = 0;
	neg = 0;
	if (nb < 0)
	{
		nb *= -1;
		c[0] = '-';
		neg++;
	}
	while ((nb > 9) && (i + neg < lenn))
	{
		c[lenn - 1 - i] = (nb % 10) + 48;
		nb = (nb / 10);
		i++;
	}
	if ((nb < 10) && (i + neg < lenn))
	{
		c[lenn - 1 - i] = nb + 48;
		i++;
	}
}

char	*ft_itoa(int n)
{
	char			*c;
	unsigned int	lenn;
	long			nb;

	lenn = ft_lennumber(n);
	nb = n;
	c = malloc (lenn + 1);
	if (!c)
		return (NULL);
	ft_itoanmbr(nb, c, lenn);
	c[lenn] = '\0';
	return (c);
}
