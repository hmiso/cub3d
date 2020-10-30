/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 16:59:53 by hmiso             #+#    #+#             */
/*   Updated: 2020/09/27 17:45:57 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void		init_structur(t_events *events)
{
	events->i = 0;
	events->j = 0;
	events->ii = 0;
	events->jj = 0;
	events->iii = 0;
	events->jjj = 0;
	events->flag_wall = 0;
	events->count_wall = 1;
}

void			events_res_seven(t_events *events, t_vars *vars)
{
	while (events->count_wall < 30)
		events_res_three(events, vars);
	if (events->flag_wall == 1)
	{
		vars->x += 0;
		vars->y += 0;
	}
	else
	{
		vars->x += 10 * cos((vars->alfa + M_PI_2));
		vars->y += 10 * sin((vars->alfa + M_PI_2));
	}
	events->count_wall = 0;
}

void			events_res_eith(t_events *events, t_vars *vars)
{
	while (events->count_wall < 30)
		events_res_four(events, vars);
	if (events->flag_wall == 1)
	{
		vars->x += 0;
		vars->y += 0;
	}
	else
	{
		vars->x += 10 * cos(vars->alfa);
		vars->y += 10 * sin(vars->alfa);
	}
	events->count_wall = 0;
}

void			events_res_nine(t_vars *vars, int keycode)
{
	if (keycode == 124)
	{
		vars->alfa += 0.0872665;
		if (vars->alfa >= 2 * M_PI)
			vars->alfa -= 2 * M_PI;
	}
	if (keycode == 123)
	{
		vars->alfa -= 0.0872665;
		if (vars->alfa <= 0)
			vars->alfa += 2 * M_PI;
	}
}

int				events(int keycode, t_vars *vars)
{
	t_events	events;

	init_structur(&events);
	if (keycode == 53)
		exit(0);
	if (keycode == 0)
		events_res_five(&events, vars);
	if (keycode == 1)
		events_res_six(&events, vars);
	if (keycode == 2)
		events_res_seven(&events, vars);
	if (keycode == 13)
		events_res_eith(&events, vars);
	events_res_nine(vars, keycode);
	mlx_destroy_image(vars->mlx, vars->img.img);
	vars->img.img = mlx_new_image(vars->mlx, vars->size_x, vars->size_y);
	vars->img.addr = mlx_get_data_addr(vars->img.img,
	&vars->img.bits_per_pixel, &vars->img.line_length, &vars->img.endian);
	vars->count_plan = 0;
	print_player(vars);
	sort_sprite(vars);
	return (0);
}
