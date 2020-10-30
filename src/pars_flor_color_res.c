/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_flor_color_res.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 11:14:13 by hmiso             #+#    #+#             */
/*   Updated: 2020/09/27 18:12:49 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		ps_fl_color_five(t_color *color, t_vars *vars, char *str)
{
	while (str[color->count_str] == ' ')
		color->count_str++;
	if (ft_isdigit(str[color->count_str]))
	{
		color->flag = (ft_atoi(&str[color->count_str]));
		if (color->flag < 0 || color->flag > 255)
		{
			ft_putstr_fd("Error\nflor color error\n", 2);
			exit(0);
		}
		while (ft_isdigit(str[color->count_str]))
			color->count_str++;
		vars->color_f += color->flag;
	}
	else
	{
		ft_putstr_fd("Error\nflor color error\n", 2);
		exit(0);
	}
}
