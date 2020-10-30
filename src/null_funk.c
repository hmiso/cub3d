/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   null_funk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 18:45:55 by hmiso             #+#    #+#             */
/*   Updated: 2020/09/26 21:47:21 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		null_funk(t_vars *vars)
{
	vars->mlx = NULL;
	vars->win = NULL;
	vars->x = 0;
	vars->y = 0;
	vars->bx = 0;
	vars->len_sprite = 0;
	vars->mas = NULL;
	vars->alfa = 0;
	vars->start = 0;
	vars->flag_wall = 0;
	vars->count_plan = 0;
	vars->len_ray = 0;
	vars->count_sprite = 0;
	vars->mas_sprite = NULL;
	vars->size_x = 0;
	vars->size_y = 0;
	vars->color_f = 0;
	vars->color_c = 0;
}
