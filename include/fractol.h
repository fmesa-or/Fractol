/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 22:09:58 by fmesa-or          #+#    #+#             */
/*   Updated: 2024/05/14 13:43:49 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Libraries */
#ifndef FRACTOL_H
# define FRACTOL_H
# include <math.h>
# include "structs.h"
# include "config.h"
# include "MLX42/MLX42.h"
# include "fr_printf.h"
# include "libft.h"

/* Functions */
	/* Basics */
void	init(t_data *data, char **argv, int argc);
void	init_color_palette(t_data *data);
void	throw_err(char *str, t_data *data);
void	zoom(t_data *data);

	/* Hooks */
void	key_hook(mlx_key_data_t keydata, void *param);
void	scroll_hook(double xdelta, double ydelta, void *param);
void	render(void *param);
void	move_y(t_data *data, double amount);

	/* Mandelbrot */
void	mandelbrot(t_data *d);
double	iter_mandel(double x0, double y0);

	/* Mandelbrot */
void	julia(t_data *data);
double	iter_julia(double x0, double y0, t_data *data);

#endif