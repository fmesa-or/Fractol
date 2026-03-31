/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsman.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:44:35 by fmesa-or          #+#    #+#             */
/*   Updated: 2024/05/14 13:24:00 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/************************************************************************
* @brief Checks if the current x and y are the same as the last x and y

* @param x The x value
* @param y The y value
* @param last_x  The last x value
* @param last_y  The last y value
* @return true
* @return false
*************************************************************************/
static bool	check_cycle(double x, double y, double *last_x, double *last_y)
{
	if (x == *last_x && y == *last_y)
		return (true);
	*last_x = x;
	*last_y = y;
	return (false);
}

/************************************************
* @brief Calculates the new values for x and y

* @param x The x value
* @param y  The y value
* @param x0  The x0 value
* @param y0  The y0 value
*************************************************/
static void	calculate_new_values(double *x, double *y, double x0, double y0)
{
	double	tempx;

	tempx = (*x) * (*x) - (*y) * (*y) + x0;
	*y = 2 * (*x) * (*y) + y0;
	*x = tempx;
}

/***********************************************************
* @brief Iterates over the current x and y

* @param d A struct containing the x, y, x0 and y0 values
* @param data The data struct
* @return double The amount of iterations
************************************************************/
static double	iterate_while_loop(t_local d)
{
	double	iteration;
	double	last_x;
	double	last_y;
	double	max_sq;

	iteration = -1;
	last_x = 0.0;
	last_y = 0.0;
	while (iteration++ < MAX_ITERATIONS)
	{
		max_sq = d.x * d.x + d.y * d.y;
		if (max_sq > 4.0)
			break ;
		calculate_new_values(&d.x, &d.y, d.x0, d.y0);
		if (check_cycle(d.x, d.y, &last_x, &last_y))
			return (MAX_ITERATIONS);
	}
	return (iteration);
}

/*****************************************************************************
* @brief A wrapper function that calculates the iterations

* It will call the iterate_while_loop function to calculate the iterations

* @param x0 The x0 value
* @param y0  The y0 value
* @param data  The data struct
* @return double The amount of iterations
******************************************************************************/
double	iter_mandel(double x0, double y0)
{
	t_local	d;
	double	ret;

	d.x = 0;
	d.y = 0;
	d.x0 = x0;
	d.y0 = y0;
	ret = iterate_while_loop(d);
	return (ret);
}
