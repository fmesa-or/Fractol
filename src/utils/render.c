/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:33:35 by fmesa-or          #+#    #+#             */
/*   Updated: 2024/05/14 13:40:23 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*********************************************
* @brief Determine which fractol to render.

* @param data The data struct.
**********************************************/
static void	determine_fractol(t_data *data)
{
	if (data->frctl == MANDELBROT)
		mandelbrot(data);
	else if (data->frctl == JULIA)
		julia(data);
}

/**************************************************************
* @brief Render hook to determine which fractol to render.
* And checks if the fractol has actually changed by the user.
* Then waits for FRAME_WAIT frames before rendering again.
* @param param The data struct.
***************************************************************/
void	render(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (data->renderer.frames < FRAME_WAIT)
	{
		data->renderer.frames++;
		return ;
	}
	data->renderer.frames = 0;
	if (data->renderer.changed)
		determine_fractol(data);
	data->renderer.changed = false;
}
