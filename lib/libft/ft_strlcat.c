/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:54:35 by fmesa-or          #+#    #+#             */
/*   Updated: 2023/12/10 21:54:35 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	lendst;
	size_t	lensrc;
	char	*src_;

	i = 0;
	lendst = 0;
	lensrc = 0;
	src_ = (char *)src;
	while (dst[lendst])
		lendst++;
	while (src_[lensrc])
		lensrc++;
	if (lendst >= dstsize)
		return (lensrc + dstsize);
	if (dstsize > 0)
	{
		while ((src_[i] != '\0') && (i < dstsize - 1 - lendst))
		{
			dst[lendst + i] = src_[i];
			i++;
		}
	}
	dst[lendst + i] = '\0';
	return (lendst + lensrc);
}
