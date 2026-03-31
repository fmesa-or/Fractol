/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 21:46:45 by fmesa-or          #+#    #+#             */
/*   Updated: 2024/01/08 21:29:54 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*s = original string.
  start = starting position
  len = max lenght.*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;
	size_t	size;
	char	*ret;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (start >= size)
	{
		ret = ft_strdup("");
		return (ret);
	}
	else if (size - start < len)
		len = size - start;
	subs = malloc (len + 1);
	if (!subs)
		return (NULL);
	i = -1;
	while (++i < len)
		subs[i] = s[i + start];
	subs[i] = '\0';
	return (subs);
}
