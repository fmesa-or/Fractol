/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:44:34 by fmesa-or          #+#    #+#             */
/*   Updated: 2024/01/08 20:57:25 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Copies a string 'src' in a string 'dst', only 'len' characters.
It considers overlap, in wich cases starts copying by the end.
Returns dst*/

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*dst_char;
	char			*src_char;
	unsigned long	i;

	dst_char = (char *)dst;
	src_char = (char *)src;
	i = 0;
	if (dst_char == 0 && src_char == 0 && len)
		return (dst);
	while (i < len)
	{
		if (dst_char < src_char)
			dst_char[i] = src_char[i];
		else
			dst_char[len - i - 1] = src_char [len - i - 1];
		i++;
	}
	return (dst);
}
