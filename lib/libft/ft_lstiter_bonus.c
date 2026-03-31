/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:51:15 by fmesa-or          #+#    #+#             */
/*   Updated: 2024/01/08 18:51:36 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	int		i;
	t_list	*temp;

	temp = lst;
	i = ft_lstsize(temp);
	while (i > 0 && temp)
	{
		f(temp->content);
		temp = temp->next;
	}
}
