/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:32:24 by fmesa-or          #+#    #+#             */
/*   Updated: 2023/12/04 19:00:54 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dst_char;
	const char	*src_char;
	size_t		i;

	dst_char = (char *)dst;
	src_char = (const char *)src;
	i = 0;
	if (dst_char == 0 && src_char == 0)
		return ("\0");
	while (i < n)
	{
		dst_char[i] = src_char[i];
		i++;
	}
	return (dst);
}
