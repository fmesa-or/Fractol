/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 21:02:42 by fmesa-or          #+#    #+#             */
/*   Updated: 2024/05/14 13:38:20 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/********************************************************
* @brief Prints an error message and exits the program  *

* @param str It's the error massage we want to print.   *
*********************************************************/

void	throw_err(char *str, t_data *data)
{
	fr_printf(RD"\nError: %s\n\n"CRESET, str);
	fr_printf("***"PRSUB"Available sets:"CRESET"***\n");
	fr_printf(GR"mandelbrot\njulia\n"CRESET);
	if (data->mlx)
	{
		mlx_close_window(data->mlx);
		mlx_terminate(data->mlx);
	}
	exit(1);
}
