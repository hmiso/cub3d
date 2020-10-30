/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stolb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 11:25:46 by hmiso             #+#    #+#             */
/*   Updated: 2020/09/26 21:47:43 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void		init_struct(t_print *print, t_vars *vars, double angle_ray)
{
	print->len = vars->len_ray;
	print->len = print->len * cos(vars->alfa - angle_ray);
	print->len_stolb = vars->size_y * 64 / print->len;
	print->start = vars->size_y / 2 - print->len_stolb / 2;
	print->yyy = print->start;
	print->end = vars->size_y / 2 + print->len_stolb / 2;
	print->coef = 64.0 / (print->start - print->end);
	print->count = 0;
	print->color = 0;
	print->count_y_pixel = 0;
	print->count_x_pixel = vars->bx;
}

void			print_stolb(t_vars *vars, double angle_ray)
{
	t_print		print;

	init_struct(&print, vars, angle_ray);
	if (print.start < 0)
		print.start = 0;
	while (print.count < print.start)
	{
		my_mlx_pixel_put(vars, vars->count_plan, print.count, vars->color_c);
		print.count++;
	}
	while (print.start < print.end && print.start < vars->size_y
	&& print.start >= 0)
	{
		print.count_y_pixel = (int)((print.yyy - print.start) * print.coef);
		print.color = get_color(vars, print.count_x_pixel, print.count_y_pixel);
		my_mlx_pixel_put(vars, vars->count_plan, print.start, print.color);
		print.start++;
	}
	while (print.end < vars->size_y)
	{
		my_mlx_pixel_put(vars, vars->count_plan, print.end, vars->color_f);
		print.end++;
	}
	vars->count_plan++;
}
