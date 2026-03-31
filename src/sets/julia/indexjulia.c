/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexjulia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 21:22:39 by fmesa-or          #+#    #+#             */
/*   Updated: 2024/05/14 13:38:01 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/***************************************************
* @brief A function that maps a value to a range

* @param x The value to map
* @param min The minimum value of the range
* @param max The maximum value of the range
* @param cords Coordinates of the range to map to
* @return double The mapped value
****************************************************/
static double	map_to_range(int x, int min, int max, t_cords cords)
{
	double	percentage;

	percentage = (double)x / (double)WIDTH;
	if (cords.min == 0 && cords.max == 0)
		return (percentage * (max - min) + min);
	return (percentage * (cords.max - cords.min) + cords.min);
}

/************************************************
* @brief The wrapper function for the julia set
*
* @param d The data struct
*************************************************/
void	julia(t_data *data)
{
	double	imgx;
	double	imgy;
	double	x0;
	double	y0;

	imgx = 0;
	while (imgx < WIDTH)
	{
		imgy = 0;
		while (imgy < HEIGHT)
		{
			x0 = map_to_range(imgx, 0, WIDTH, data->x);
			y0 = map_to_range(imgy, 0, HEIGHT, data->y);
			data->iter = iter_julia(x0, y0, data);
			mlx_put_pixel(data->img, imgx, imgy,
				data->palette[data->iter % MAX_ITERATIONS]);
			imgy++;
		}
		imgx++;
	}
}
