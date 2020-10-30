/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_res_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 18:03:49 by hmiso             #+#    #+#             */
/*   Updated: 2020/09/23 18:05:50 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void			events_res_five(t_events *events, t_vars *vars)
{
	while (events->count_wall < 30)
		events_res(events, vars);
	if (events->flag_wall == 1)
	{
		vars->x += 0;
		vars->y += 0;
	}
	else
	{
		vars->x -= 10 * cos((vars->alfa + M_PI_2));
		vars->y -= 10 * sin((vars->alfa + M_PI_2));
	}
	events->count_wall = 0;
}

void			events_res_six(t_events *events, t_vars *vars)
{
	while (events->count_wall < 30)
		events_res_two(events, vars);
	if (events->flag_wall == 1)
	{
		vars->x += 0;
		vars->y += 0;
	}
	else
	{
		vars->x -= 10 * cos(vars->alfa);
		vars->y -= 10 * sin(vars->alfa);
	}
	events->count_wall = 0;
}
