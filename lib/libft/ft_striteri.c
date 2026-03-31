/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:32:01 by fmesa-or          #+#    #+#             */
/*   Updated: 2023/12/14 19:49:26 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*To each character from 's' string, it aplies 'f' function.
  'f' has as parameters index and direction of each char.*/

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
