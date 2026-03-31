/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:53:29 by fmesa-or          #+#    #+#             */
/*   Updated: 2023/12/14 20:06:21 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*To each character from the string 's' it aplies the 'f' function.
  Makes a new string with the resault.*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	unsigned int	i;
	char			*str;

	len = ft_strlen(s) + 1;
	i = 0;
	str = malloc (len);
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, (char) s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
