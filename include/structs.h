/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 21:33:39 by fmesa-or          #+#    #+#             */
/*   Updated: 2024/05/14 13:23:21 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "fractol.h"
# include "MLX42/MLX42.h"
# include "config.h"

/*****************************************************************************
* @brief The struct that holds the current x and y values for utils madelbrot

* It also holds the last x and y values
* @param x The x value
* @param y The y value
* @param x0 The last x value
* @param y0 The last y value
******************************************************************************/
typedef struct s_local
{
	double	x0;
	double	y0;
	double	x;
	double	y;
}				t_local;

/*****************************************************************************
* @brief A struct to store the x and y coordinates of the pixel on mandelbrot
******************************************************************************/
typedef struct s_imgmandelbrot
{
	int		x;
	int		y;
	double	x0;
	double	y0;
}				t_imgman;

/******************************************
* @brief Enumeration of available fractals
*******************************************/
typedef enum e_sets
{
	MANDELBROT,
	JULIA,
}				t_fractals;

/**************************************
* @brief The coordinates of a point

* @param min The minimum value
* @param max The maximum value
**************************************/
typedef struct s_cords
{
	double		min;
	double		max;
}				t_cords;

/*************************************
* @brief The complex number struct

* @param r The real part
* @param i The imaginary part
*************************************/
typedef struct s_complex
{
	double		r;
	double		i;
}				t_complex;

/************************************************
* @brief The zoom level

* @param x The x coordinate of the zoom point
* @param y The y coordinate of the zoom point
* @param factor The zoom factor
************************************************/
typedef struct s_zoom
{
	double		x;
	double		y;
	double		factor;
	double		level;
}				t_zoom;

/******************************
* @brief The mouse position

* @param x The x coordinate
* @param y The y coordinate
******************************/
typedef struct s_mouse
{
	int32_t		x;
	int32_t		y;
}				t_mouse;

/****************************************************************************
* @brief

* This struct is used to track changes in the fractal. If there has been a
* change, the fractal will be rendered again. This is to prevent the fractal
* from being rendered every frame.

* @example If the user changes the color, the fractal will be rendered again

* @param frames The number of frames to wait before rendering
* @param changed Whether there has been a change by the user
*****************************************************************************/
typedef struct s_renderer
{
	int			frames;
	bool		changed;
}				t_renderer;

/**********************************
* @brief The color offset struct

* @param r_o The red offset
* @param g_o The green offset
* @param b_o The blue offset
***********************************/
typedef struct s_color
{
	double		r_o;
	double		g_o;
	double		b_o;
}				t_color;

/*******************************************************
* @brief The main data struct
*
* @param mlx The MLX42 struct
* @param img The image struct
* @param frctl The fractal to be drawn
* @param iter The maximum number of iterations
* @param x Struct containing the x range
* @param y Struct containing the y range
* @param complex The complex number (used in julia set)
* @param zoom The zoom level
* @param mouse The mouse position
* @param renderer The render struct to track changes
* @param color Struct containing the color value
* @param palette The color palette (precalculated)
*******************************************************/
typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_fractals	frctl;
	u_int32_t	iter;
	t_cords		x;
	t_cords		y;
	t_complex	complex;
	t_zoom		zoom;
	t_mouse		mouse;
	t_renderer	renderer;
	t_color		color;
	uint32_t	palette[MAX_ITERATIONS];
}								t_data;

#endif