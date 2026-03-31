/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:41:21 by fmesa-or          #+#    #+#             */
/*   Updated: 2023/12/20 19:40:18 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	i;
	long	n;
	int		neg;

	i = 0;
	n = 0;
	neg = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		neg *= -neg;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n += str[i] - 48;
		if (str[i + 1] >= '0' && str[i + 1] <= '9')
			n *= 10;
		i++;
	}
	return (n * neg);
}
