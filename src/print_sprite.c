/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 16:33:00 by hmiso             #+#    #+#             */
/*   Updated: 2020/09/26 19:04:14 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void		init_struckt(t_sprite *sprite, t_vars *vars,
double spr_x, double spr_y)
{
	sprite->sprite_dir = atan2(spr_y - vars->y, spr_x - vars->x);
	while (sprite->sprite_dir - vars->alfa > M_PI)
		sprite->sprite_dir -= 2 * M_PI;
	while (sprite->sprite_dir - vars->alfa < -M_PI)
		sprite->sprite_dir += 2 * M_PI;
	sprite->sprite_dist = sqrt((powf((spr_x - vars->x), 2)
	+ powf((spr_y - vars->y), 2)));
	sprite->sprite_screen_size = vars->size_y * 64 / sprite->sprite_dist;
	sprite->h_offset = (sprite->sprite_dir - vars->alfa) * (vars->size_x)
	/ (M_PI / 3) + (vars->size_x) / 2 - sprite->sprite_screen_size / 2;
	sprite->v_offset = vars->size_y / 2 - sprite->sprite_screen_size / 2;
	sprite->i = 0;
	sprite->j = 0;
	sprite->count = fabs((sprite->h_offset - vars->mas_ray[0]));
	sprite->step = M_PI / (vars->size_x * 3.0);
	sprite->color = 0;
}

static void		print_sprite_res(t_sprite *sprite, t_vars *vars)
{
	while (sprite->j < sprite->sprite_screen_size)
	{
		if (sprite->v_offset + (int)(sprite->j) < 0
		|| sprite->v_offset + sprite->j >= (int)vars->size_y)
		{
			sprite->j++;
			continue;
		}
		sprite->color = sp_get_color(vars, sprite->i * 64 /
		sprite->sprite_screen_size, sprite->j * 64 /
		sprite->sprite_screen_size);
		if (sprite->color != 0X980088)
			my_mlx_pixel_put(vars, sprite->h_offset +
			sprite->i, sprite->v_offset + sprite->j, sprite->color);
		sprite->j++;
	}
	sprite->step += M_PI / (vars->size_x * 3.0);
	sprite->j = 0;
	sprite->i++;
	sprite->count++;
}

void			print_sprite(double spr_x, double spr_y, t_vars *vars)
{
	t_sprite	sprite;

	init_struckt(&sprite, vars, spr_x, spr_y);
	if (sprite.sprite_screen_size > 4000)
		sprite.sprite_screen_size = 0;
	while (sprite.i < sprite.sprite_screen_size)
	{
		if (sprite.h_offset + (int)(sprite.i) < 0 ||
		sprite.h_offset + sprite.i >= (int)vars->size_x)
		{
			sprite.i++;
			continue;
		}
		if (vars->mas_ray[(int)sprite.h_offset + sprite.i] < sprite.sprite_dist)
		{
			sprite.i++;
			continue;
		}
		print_sprite_res(&sprite, vars);
	}
}
