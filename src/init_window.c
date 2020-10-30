/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 10:35:55 by hmiso             #+#    #+#             */
/*   Updated: 2020/09/27 18:08:16 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_window(t_vars *vars)
{
	vars->win = mlx_new_window(vars->mlx, vars->size_x,
	vars->size_y, "Cub3D");
	vars->img.img = mlx_new_image(vars->mlx,
	vars->size_x, vars->size_y);
	vars->img.addr = mlx_get_data_addr(vars->img.img,
	&vars->img.bits_per_pixel,
	&vars->img.line_length, &vars->img.endian);
	if (vars->img.addr == NULL)
	{
		ft_putstr_fd("Error\nmallok in init_window\n", 2);
		exit(0);
	}
}
