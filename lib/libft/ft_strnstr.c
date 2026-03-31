/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:53:15 by fmesa-or          #+#    #+#             */
/*   Updated: 2023/12/12 21:41:24 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Looks for a string inside a bigger string. Only looks for 'len' characters.
Every char after '\0' it's not checked.*/

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*ndle;
	char	*hystck;
	size_t	i;
	size_t	j;

	ndle = (char *)needle;
	hystck = (char *)haystack;
	i = 0;
	if (ndle[0] == '\0')
		return (hystck);
	while (hystck[i] && i < len)
	{
		j = 0;
		while (hystck[i + j] == ndle[j] && i + j < len)
		{
			if (ndle[j + 1] == '\0' && j + 1 <= len)
				return (&hystck[i]);
			j++;
		}
		i++;
	}
	return (0);
}
