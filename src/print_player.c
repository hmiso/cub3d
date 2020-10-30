/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 16:28:51 by hmiso             #+#    #+#             */
/*   Updated: 2020/09/27 09:14:11 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		print_player(t_vars *vars)
{
	double	start;
	double	end;
	double	step;
	int		len;

	start = vars->alfa - M_PI / 6;
	end = vars->alfa + M_PI / 6;
	step = M_PI / (vars->size_x * 3.0);
	len = 0;
	while (start < (end - step))
	{
		vars->len_ray = count_rastoinie(vars->mas, start, vars);
		print_stolb(vars, start);
		start += step;
		vars->mas_ray[len] = vars->len_ray;
		len++;
	}
}
