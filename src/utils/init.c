/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:09:56 by fmesa-or          #+#    #+#             */
/*   Updated: 2024/05/14 13:39:46 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "config.h"

/*********************************************
* @brief Starts mlx and create the image

* @param mlx The mlx pointer
* @param data The data struct
**********************************************/
static void	start_mlx(mlx_t *mlx, t_data *data)
{
	if (!mlx)
		throw_err("Feiled to initialize", data);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	data->mlx = mlx;
	data->img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!data->img)
		throw_err("mlx_new_image is eepy", data);
}

/************************************
* @brief Constructs the data struct

* @param data The data struct
*************************************/
static void	construct(t_data *data)
{
	data->x.min = -2;
	data->x.max = 2;
	data->y.min = -2;
	data->y.max = 2;
	data->zoom.factor = 1.0;
	data->renderer.frames = FRAME_WAIT;
	data->renderer.changed = true;
	data->color.r_o = 9;
	data->color.g_o = 15;
	data->color.b_o = 8.5;
	if (data->frctl == MANDELBROT)
	{
		data->complex.r = -0.7;
		data->complex.i = 0.27015;
	}
}

/**************************************************************
* @brief Checks if we have an invalid number

* @param str The string to check
* @return true When it's an invalid number
* @return false When it's a valid number

* @example valid -> -0.457 / 0.66 / 1 / -1
* @example invalid -> 0.-457 / 0.6.6 / ++1 / --1 / +-0..6.6
**************************************************************/

static bool	invalid(char *str)
{
	int	i;
	int	c_dots;

	i = 0;
	c_dots = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!ft_isdigit(str[i++]))
		return (true);
	while (str[i] && (ft_isdigit(str[i]) || (c_dots == 0 && str[i] == '.')))
	{
		if (str[i] == '.')
			c_dots = 1;
		i++;
	}
	if (str[i])
		return (true);
	return (false);
}

/***************************************************************
 * @brief Parses the arguments and sets the fractal
 *
 * @param ac The argument count
 * @param av The argument list
 * @param data The data struct
 **************************************************************/
static void	parse_argv(t_data *data, char **argv, int argc)
{
	if (argc == 1)
		throw_err("Use -> ./fractol [fractal] [r]* [i]*\n  *For julia", data);
	if (ft_strncmp(argv[1], "mandelbrot", (sizeof(argv[1]))) == 0 && argc == 2)
		data->frctl = MANDELBROT;
	else if (ft_strncmp(argv[1], "julia", (sizeof(argv[1]))) == 0 && argc == 4)
	{
		data->frctl = JULIA;
		if (invalid(argv[2]) || invalid(argv[3]))
			throw_err("[r] and [i] must be valid. Try using number.", data);
		data->complex.r = ft_atod(argv[2]);
		data->complex.i = ft_atod(argv[3]);
		if ((data->complex.r > 2 || data->complex.r < -2)
			|| (data->complex.i > 2 || data->complex.i < -2))
			throw_err("For julia set, values must be between -2 and 2", data);
	}
	else
		throw_err("Use -> ./fractol [fractal] [r]* [i]*\n  *For julia", data);
	construct (data);
	init_color_palette(data);
}

/*************************************************
* @brief All the steps for initialize

* @param data The data struct
* @param av The arguments
* @param ac The amount of arguments
*************************************************/
void	init(t_data *data, char **argv, int argc)
{
	ft_bzero (data, sizeof(data));
	parse_argv(data, argv, argc);
	start_mlx(mlx_init(WIDTH, HEIGHT, "Fractol", true), data);
}
