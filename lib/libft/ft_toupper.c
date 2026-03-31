/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:23:19 by fmesa-or          #+#    #+#             */
/*   Updated: 2023/12/12 21:48:24 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
	{
		return (c - 32);
	}
	return (c);
}
/*
int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        printf("%c\n", ft_toupper( argv[1][0]));
    }
    return (0);
}*/