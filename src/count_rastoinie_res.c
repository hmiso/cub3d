/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_rastoinie_res.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 16:25:13 by hmiso             #+#    #+#             */
/*   Updated: 2020/09/26 21:47:12 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	resurs_ray_four(t_raycast *raycast, char **mas, t_vars *vars)
{
	while (raycast->j1 < vars->end_mas_y &&
	raycast->i1 >= 0 && raycast->j1 >= 0 &&
	raycast->i1 <= (int)ft_strlen(mas[raycast->j1]) &&
	mas[raycast->j1][raycast->i1] != '1')
	{
		raycast->bx = raycast->bx + raycast->xa;
		raycast->by = raycast->by + raycast->ya;
		raycast->i1 = raycast->bx / 64;
		raycast->j1 = raycast->by / 64;
	}
}

double	resurs_ray_five(t_raycast *raycast, t_vars *vars, double pow)
{
	if (pow > M_PI)
	{
		vars->bx = (int)raycast->ax % 64 + (raycast->ax - (int)raycast->ax);
		vars->text.addr = vars->text.addr_n;
	}
	else
	{
		vars->bx = -(int)raycast->ax % 64 +
		63 + (raycast->ax - (int)raycast->ax);
		vars->text.addr = vars->text.addr_s;
	}
	return (raycast->len_gor);
}

double	resurs_ray_six(t_raycast *raycast, t_vars *vars, double pow)
{
	if ((pow < 2 * M_PI && pow > 3 * M_PI / 2 && pow != M_PI_2) ||
	(pow > 0 && pow < M_PI_2))
	{
		vars->text.addr = vars->text.addr_e;
		vars->bx = (int)raycast->by % 64 + (raycast->by - (int)raycast->by);
	}
	else
	{
		vars->text.addr = vars->text.addr_w;
		vars->bx = -(int)raycast->by % 64 + 63 +
		(raycast->by - (int)raycast->by);
	}
	return (raycast->len_ver);
}
