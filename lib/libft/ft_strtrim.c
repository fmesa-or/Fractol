/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:03:15 by fmesa-or          #+#    #+#             */
/*   Updated: 2024/01/08 21:26:51 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*s1 it's gonna be trimed.
  set has the characters we are gonna use for triming.
  Keeps the string in between the removed characters
  (removes at the front and int the back until 
  it finds somehting not inside 'set').*/

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len;
	char	*str;
	char	*ret;

	i = 0;
	len = ft_strlen(s1) - 1;
	while ((i <= len) && ft_strchr(set, s1[i]))
		i++;
	if (!s1[0] || i > len)
	{
		if (!s1[0])
			ret = ft_strdup("");
		else
			ret = ft_strdup(&s1[len + 1]);
		return (ret);
	}
	while ((ft_strchr(set, s1[len]) && (len >= 0)))
		len--;
	str = malloc(sizeof(char) * (len - i + 2));
	if (str == NULL)
		return (NULL);
	s1 = s1 + i;
	ft_strlcpy(str, s1, len - i + 2);
	return (str);
}
