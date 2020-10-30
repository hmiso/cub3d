/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_res.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 18:01:04 by hmiso             #+#    #+#             */
/*   Updated: 2020/09/23 18:05:37 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void			events_res(t_events *events, t_vars *vars)
{
	events->i = (vars->x - events->count_wall *
	cos((vars->alfa + M_PI_2))) / 64;
	events->j = (vars->y - events->count_wall *
	sin((vars->alfa + M_PI_2))) / 64;
	events->ii = (vars->x - events->count_wall *
	cos((vars->alfa + M_PI / 6 + M_PI_2))) / 64;
	events->jj = (vars->y - events->count_wall *
	sin((vars->alfa + M_PI / 6 + M_PI_2))) / 64;
	events->iii = (vars->x - events->count_wall *
	cos((vars->alfa - M_PI / 6 + M_PI_2))) / 64;
	events->jjj = (vars->y - events->count_wall *
	sin((vars->alfa - M_PI / 6 + M_PI_2))) / 64;
	if (vars->mas[events->j][events->i] == '1' ||
	vars->mas[events->jj][events->ii] == '1' ||
	vars->mas[events->jjj][events->iii] == '1')
		events->flag_wall = 1;
	events->count_wall++;
}

void			events_res_two(t_events *events, t_vars *vars)
{
	events->i = (vars->x - events->count_wall *
	cos(vars->alfa)) / 64;
	events->j = (vars->y - events->count_wall *
	sin(vars->alfa)) / 64;
	events->ii = (vars->x - events->count_wall *
	cos((vars->alfa + M_PI / 6))) / 64;
	events->jj = (vars->y - events->count_wall *
	sin((vars->alfa + M_PI / 6))) / 64;
	events->iii = (vars->x - events->count_wall *
	cos((vars->alfa - M_PI / 6))) / 64;
	events->jjj = (vars->y - events->count_wall *
	sin((vars->alfa - M_PI / 6))) / 64;
	if (vars->mas[events->j][events->i] == '1' ||
	vars->mas[events->jj][events->ii] == '1' ||
	vars->mas[events->jjj][events->iii] == '1')
		events->flag_wall = 1;
	events->count_wall++;
}

void			events_res_three(t_events *events, t_vars *vars)
{
	events->i = (vars->x + events->count_wall *
	cos((vars->alfa + M_PI_2))) / 64;
	events->j = (vars->y + events->count_wall *
	sin((vars->alfa + M_PI_2))) / 64;
	events->ii = (vars->x + events->count_wall *
	cos((vars->alfa + M_PI_2 + M_PI / 6))) / 64;
	events->jj = (vars->y + events->count_wall *
	sin((vars->alfa + M_PI_2 + M_PI / 6))) / 64;
	events->iii = (vars->x + events->count_wall *
	cos((vars->alfa + M_PI_2 - M_PI / 6))) / 64;
	events->jjj = (vars->y + events->count_wall *
	sin((vars->alfa + M_PI_2 - M_PI / 6))) / 64;
	if (vars->mas[events->j][events->i] == '1' ||
	vars->mas[events->jj][events->ii] == '1' ||
	vars->mas[events->jjj][events->iii] == '1')
		events->flag_wall = 1;
	events->count_wall++;
}

void			events_res_four(t_events *events, t_vars *vars)
{
	events->i = (vars->x + events->count_wall *
	cos(vars->alfa)) / 64;
	events->j = (vars->y + events->count_wall *
	sin(vars->alfa)) / 64;
	events->ii = (vars->x + events->count_wall *
	cos(vars->alfa + M_PI / 6)) / 64;
	events->jj = (vars->y + events->count_wall *
	sin(vars->alfa + M_PI / 6)) / 64;
	events->iii = (vars->x + events->count_wall *
	cos(vars->alfa - M_PI / 6)) / 64;
	events->jjj = (vars->y + events->count_wall *
	sin(vars->alfa - M_PI / 6)) / 64;
	if (vars->mas[events->j][events->i] == '1' ||
	vars->mas[events->jj][events->ii] == '1' ||
	vars->mas[events->jjj][events->iii] == '1')
		events->flag_wall = 1;
	events->count_wall++;
}
