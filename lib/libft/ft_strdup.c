/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 21:27:39 by fmesa-or          #+#    #+#             */
/*   Updated: 2023/12/12 21:35:10 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Allocates enough memory to copy 's1'. Copies and returns the pointer.
If there is no enough space available for memory, returns NULL*/

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	char	*s1_;
	int		i;

	s1_ = (char *)s1;
	i = 0;
	while (s1_[i])
		i++;
	ptr = malloc(i + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1_[i])
	{
		ptr[i] = s1_[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
