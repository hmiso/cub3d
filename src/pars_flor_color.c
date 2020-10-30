/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_flor_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 08:44:19 by hmiso             #+#    #+#             */
/*   Updated: 2020/09/27 18:13:03 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void			init_struct(t_color *color)
{
	color->ptr = NULL;
	color->flag = 0;
	color->count_str = 0;
	color->count_mas = 0;
}

static void			ps_fl_color_res(t_color *color, char *str)
{
	while (str[color->count_str] == ' ')
		color->count_str++;
	if (str[color->count_str] == ',')
		color->count_str++;
	else
	{
		ft_putstr_fd("Error\nflor color error\n", 2);
		exit(0);
	}
}

static void			ps_fl_color_two(t_color *color, t_vars *vars, char *str)
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
		vars->color_f = (color->flag << 16);
	}
	else
	{
		ft_putstr_fd("Error\nflor color error\n", 2);
		exit(0);
	}
}

static void			ps_fl_color_three(t_color *color, t_vars *vars, char *str)
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
		vars->color_f += (color->flag << 8);
	}
	else
	{
		ft_putstr_fd("Error\nflor color error\n", 2);
		exit(0);
	}
}

void				pars_flor_color(t_vars *vars, char *str)
{
	t_color		color;

	init_struct(&color);
	while (str[color.count_str] != '\0')
	{
		ps_fl_color_two(&color, vars, str);
		ps_fl_color_res(&color, str);
		ps_fl_color_three(&color, vars, str);
		ps_fl_color_res(&color, str);
		ps_fl_color_five(&color, vars, str);
		while (str[color.count_str] == ' ')
			color.count_str++;
		if (str[color.count_str] != ' ' && str[color.count_str] != '\0')
		{
			ft_putstr_fd("Error\nflor color error\n", 2);
			exit(0);
		}
	}
}
