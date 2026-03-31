/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:27:39 by fmesa-or          #+#    #+#             */
/*   Updated: 2023/12/18 21:52:45 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	n;
	char	*dst_;
	char	*src_;

	i = 0;
	n = 0;
	dst_ = dst;
	src_ = (char *)src;
	while (src[n] != '\0')
		n++;
	if (dstsize == 0)
		return (n);
	if (dstsize != '\0')
	{
		while (i < dstsize - 1 && i < n)
		{
			dst_[i] = src_[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (n);
}
