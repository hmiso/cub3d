/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_rastoinie.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 11:39:55 by hmiso             #+#    #+#             */
/*   Updated: 2020/09/27 12:49:56 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void		init_struckt(t_raycast *raycast, t_vars *vars)
{
	raycast->xa = 0;
	raycast->ya = 0;
	raycast->px = vars->x;
	raycast->py = vars->y;
	raycast->ay = 0;
	raycast->ax = 0;
	raycast->bx = 0;
	raycast->by = 0;
	raycast->len_gor = 0;
	raycast->len_ver = 0;
	raycast->i = 0;
	raycast->j = 0;
	raycast->i1 = 0;
	raycast->j1 = 0;
	raycast->end_mas_y = 0;
}

void			resurs_ray(t_raycast *raycast, t_vars *vars, double *pow)
{
	if (*pow > 0 && *pow < M_PI)
	{
		raycast->ay = (int)(raycast->py / 64) * 64 + 64;
		raycast->ya = 64;
		raycast->ax = raycast->px + (raycast->py - raycast->ay) /
		tanf((M_PI * 2 - *pow));
		raycast->xa = 64 / tanf(*pow);
	}
	else if (*pow == M_PI || *pow == 0)
	{
		raycast->ay = raycast->py;
		raycast->ya = 64;
	}
	else
	{
		raycast->ay = (int)(raycast->py / 64) * 64 - 0.000000001;
		raycast->ya = -64;
		if (tanf((M_PI * 2 - *pow)) == 0)
			*pow = *pow - M_PI / (vars->size_x * 3.0);
		raycast->ax = raycast->px + (raycast->py - raycast->ay) /
		tanf((M_PI * 2 - *pow));
		raycast->xa = 64 / tanf(M_PI * 2 - *pow);
	}
}

void			resurs_ray_two(t_raycast *raycast, double pow)
{
	if ((pow < 2 * M_PI && pow > 3 * M_PI / 2 &&
	pow != M_PI_2) || (pow > 0 && pow < M_PI_2))
	{
		raycast->bx = (int)(raycast->px / 64) * 64 + 64;
		raycast->xa = 64;
		raycast->by = raycast->py + (raycast->px -
		raycast->bx) * tanf(M_PI * 2 - pow);
		raycast->ya = 64 * tanf(pow);
	}
	else if (pow == M_PI_2 || pow == 3 * M_PI / 2)
	{
		raycast->bx = raycast->px;
		raycast->xa = 64;
	}
	else
	{
		raycast->bx = (int)(raycast->px / 64) * 64 - 0.000000001;
		raycast->xa = -64;
		raycast->by = raycast->py + (raycast->px - raycast->bx) *
		tanf(M_PI * 2 - pow);
		raycast->ya = 64 * tanf(M_PI * 2 - pow);
	}
}

void			resurs_ray_three(t_raycast *raycast, char **mas, t_vars *vars)
{
	while (raycast->j < vars->end_mas_y &&
	raycast->i >= 0 && raycast->j >= 0 &&
	raycast->i <= (int)ft_strlen(mas[raycast->j])
	&& mas[raycast->j][raycast->i] != '1')
	{
		raycast->ax = raycast->ax + raycast->xa;
		raycast->ay = raycast->ay + raycast->ya;
		raycast->i = raycast->ax / 64;
		raycast->j = raycast->ay / 64;
	}
}

double			count_rastoinie(char **mas, double pow, t_vars *vars)
{
	t_raycast	raycast;

	init_struckt(&raycast, vars);
	if (pow < 0)
		pow += 2 * M_PI;
	if (pow > 2 * M_PI)
		pow -= 2 * M_PI;
	while (mas[vars->end_mas_y] != NULL)
		vars->end_mas_y++;
	resurs_ray(&raycast, vars, &pow);
	raycast.i = raycast.ax / 64;
	raycast.j = raycast.ay / 64;
	resurs_ray_three(&raycast, mas, vars);
	resurs_ray_two(&raycast, pow);
	raycast.i1 = raycast.bx / 64;
	raycast.j1 = raycast.by / 64;
	resurs_ray_four(&raycast, mas, vars);
	raycast.len_gor = sqrt((powf((raycast.px - raycast.ax), 2) +
	powf((raycast.py - raycast.ay), 2)));
	raycast.len_ver = sqrt((powf((raycast.px - raycast.bx), 2) +
	powf((raycast.py - raycast.by), 2)));
	if (raycast.len_gor <= raycast.len_ver)
		return (resurs_ray_five(&raycast, vars, pow));
	else
		return (resurs_ray_six(&raycast, vars, pow));
}
