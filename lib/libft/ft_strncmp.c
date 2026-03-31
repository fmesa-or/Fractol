/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 21:00:40 by fmesa-or          #+#    #+#             */
/*   Updated: 2023/12/12 21:41:21 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*compares 'n' bytes or stops comparing when reaching NULL
returns -1, 0 or 1.*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n && n != 0)
	{
		if (str1[i] > str2[i])
			return (1);
		else if (str1[i] < str2[i])
			return (-1);
		else if (str1[i] == '\0' && str2[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}
