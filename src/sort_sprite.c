/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 17:21:30 by hmiso             #+#    #+#             */
/*   Updated: 2020/09/26 21:19:31 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void		init_struct(t_sort *sort)
{
	sort->count = 0;
	sort->count2 = 1;
	sort->count3 = 0;
	sort->len_sprite1 = 0;
	sort->len_sprite2 = 0;
	sort->spr_x = 0;
	sort->spr_y = 0;
}

static void		sort_sp_res(t_sort *sort, t_vars *vars)
{
	sort->spr_x = vars->mas_sprite[sort->count - 2];
	sort->spr_y = vars->mas_sprite[sort->count2 - 2];
	vars->mas_sprite[sort->count - 2] = vars->mas_sprite[sort->count];
	vars->mas_sprite[sort->count2 - 2] = vars->mas_sprite[sort->count2];
	vars->mas_sprite[sort->count] = sort->spr_x;
	vars->mas_sprite[sort->count2] = sort->spr_y;
}

static void		sort_sp_res_two(t_sort *sort, t_vars *vars)
{
	sort->len_sprite1 = sqrt((powf((vars->mas_sprite[sort->count]
	- vars->x), 2) + powf((vars->mas_sprite[sort->count2]
	- vars->y), 2)));
	sort->len_sprite2 = sqrt((powf((vars->mas_sprite[sort->count + 2]
	- vars->x), 2) + powf((vars->mas_sprite[sort->count2 + 2]
	- vars->y), 2)));
	sort->count += 2;
	sort->count2 += 2;
}

void			sort_sprite(t_vars *vars)
{
	t_sort		sort;

	init_struct(&sort);
	while (sort.count3 < vars->count_sprite - 1)
	{
		while (sort.count2 < vars->count_sprite - 1)
		{
			sort_sp_res_two(&sort, vars);
			if (sort.len_sprite1 < sort.len_sprite2)
			{
				sort_sp_res(&sort, vars);
				break ;
			}
		}
		sort.count3++;
	}
	init_struct(&sort);
	while (sort.count2 < vars->count_sprite)
	{
		print_sprite(vars->mas_sprite[sort.count],
		vars->mas_sprite[sort.count2], vars);
		sort.count += 2;
		sort.count2 += 2;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}
