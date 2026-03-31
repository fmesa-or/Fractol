/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 20:42:12 by fmesa-or          #+#    #+#             */
/*   Updated: 2023/12/12 21:42:27 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Returns a string from the position of the first apearance of 'c'.*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)s;
	while (str[i])
		i++;
	while (str[i] != (char)c && i > 0)
	{
		i--;
	}
	if (str[i] == (char)c)
		return (&str[i]);
	return (NULL);
}
