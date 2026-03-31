/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:29:03 by fmesa-or          #+#    #+#             */
/*   Updated: 2023/12/12 21:37:00 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Reserves memory (with malloc) and returns a new string
 formed by the concatenation of 's1' and 's2'*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	sizestr;
	size_t	i;
	size_t	j;

	sizestr = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(sizestr);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = (char )s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = (char )s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
