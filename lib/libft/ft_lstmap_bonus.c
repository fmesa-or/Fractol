/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:51:53 by fmesa-or          #+#    #+#             */
/*   Updated: 2024/01/09 18:47:53 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*temp;
	void	*str;

	newlst = NULL;
	while (lst)
	{
		str = ((*f)(lst->content));
		if (!str)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		temp = ft_lstnew(str);
		if (!(temp))
		{
			ft_lstclear(&newlst, del);
			free (str);
			return (NULL);
		}
		ft_lstadd_back(&newlst, temp);
		lst = lst->next;
	}
	return (newlst);
}
