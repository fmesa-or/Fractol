/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 22:50:40 by fmesa-or          #+#    #+#             */
/*   Updated: 2024/05/14 13:37:27 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/****************************************************************************
* @brief Initialize the color palette

* Formulas from https://krazydad.com/tutorials/makecolors.php
*
* @param data The data struct
****************************************************************************/
void	init_color_palette(t_data *data)
{
	int		i;
	double	t;
	int		r;
	int		g;
	int		b;

	i = 1;
	data->palette[0] = 0XAA;
	while (i < MAX_ITERATIONS)
	{
		t = (double)i / (MAX_ITERATIONS / 2);
		r = (int)data->color.r_o * (1 - t) * t * t * t * 255;
		g = (int)data->color.g_o * (1 - t) * (1 - t) * t * t * 255;
		b = (int)data->color.b_o * (1 - t) * (1 - t) * (1 - t) * t * 255;
		data->palette[i] = (r << 24) | (g << 16) | (b << 8) | 255;
		i++;
	}
}
