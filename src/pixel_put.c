/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 11:21:38 by hmiso             #+#    #+#             */
/*   Updated: 2020/09/23 11:23:21 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void			my_mlx_pixel_put(t_vars *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.addr + (y * data->img.line_length
	+ x * (data->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int				get_color(t_vars *data, int x, int y)
{
	char	*dst;

	dst = data->text.addr + (y * data->text.line_length
	+ x * (data->text.bits_per_pixel / 8));
	return (*(unsigned int*)dst);
}

int				sp_get_color(t_vars *data, int x, int y)
{
	char	*dst;

	dst = data->text.addr_spr + (y * data->text.line_length
	+ x * (data->text.bits_per_pixel / 8));
	return (*(unsigned int*)dst);
}
