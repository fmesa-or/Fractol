/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:23:14 by fmesa-or          #+#    #+#             */
/*   Updated: 2024/05/13 22:38:24 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	reset_cords(t_data *data)
{
	data->x.min = -2;
	data->x.max = 2;
	data->y.min = -2;
	data->y.max = 2;
	data->zoom.factor = 1;
	data->zoom.x = 0;
	data->zoom.y = 0;
	data->color.r_o = 9;
	data->color.g_o = 15;
	data->color.b_o = 8.5;
	init_color_palette(data);
}

/***************************************************************
* @brief Move the fractal in the x and y direction
* and limit it to the range of the fractal so when zoomed in
* the fractal is less likely to move out of view

* @param data The data struct
* @param amount The amount to move
****************************************************************/
static void	move_x(t_data *data, double amount)
{
	double	movement_factor;
	double	range_per_pixel;
	double	pixel_per_click;

	pixel_per_click = 250;
	range_per_pixel = (data->x.max - data->x.min) / WIDTH;
	movement_factor = 1.0 / (1.0 + pow(log10(data->zoom.factor), 2));
	movement_factor = fmin(movement_factor, pixel_per_click * range_per_pixel);
	data->x.min += amount * movement_factor;
	data->x.max += amount * movement_factor;
}

void	move_y(t_data *data, double amount)
{
	double	movement_factor;
	double	range_per_pixel;
	double	pixel_per_click;

	pixel_per_click = 250;
	range_per_pixel = (data->y.max - data->y.min) / HEIGHT;
	movement_factor = 1.0 / (1.0 + pow(log10(data->zoom.factor), 2));
	movement_factor = fmin(movement_factor, pixel_per_click * range_per_pixel);
	data->y.min += amount * movement_factor;
	data->y.max += amount * movement_factor;
}

/**********************************
* @brief The key hook

* @param keydata The key data
* @param param The data struct
***********************************/
void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	(void)keydata;
	data = (t_data *)param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
		move_y(data, -0.1);
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
		move_y(data, 0.1);
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		move_x(data, 0.1);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		move_x(data, -0.1);
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_R))
		reset_cords(data);
	data->renderer.changed = true;
}
