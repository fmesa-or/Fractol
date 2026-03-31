/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:21:39 by fmesa-or          #+#    #+#             */
/*   Updated: 2023/12/20 18:58:30 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	i;
	int	j;

	i = ft_lstsize(lst);
	j = 0;
	while (j < i - 1 && lst)
	{
		lst = lst->next;
		j++;
	}
	return (lst);
}
