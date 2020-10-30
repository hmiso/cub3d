/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_celling_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 10:19:01 by hmiso             #+#    #+#             */
/*   Updated: 2020/09/27 18:10:06 by hmiso            ###   ########.fr       */
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

static void			ps_cl_color_res(t_color *color, char *str)
{
	while (str[color->count_str] == ' ')
		color->count_str++;
	if (str[color->count_str] == ',')
		color->count_str++;
	else
	{
		ft_putstr_fd("Error\ncelling color error\n", 2);
		exit(0);
	}
}

static void			ps_cl_color_two(t_color *color, t_vars *vars, char *str)
{
	while (str[color->count_str] == ' ')
		color->count_str++;
	if (ft_isdigit(str[color->count_str]))
	{
		color->flag = (ft_atoi(&str[color->count_str]));
		if (color->flag < 0 || color->flag > 255)
		{
			ft_putstr_fd("Error\ncelling color error\n", 2);
			exit(0);
		}
		while (ft_isdigit(str[color->count_str]))
			color->count_str++;
		vars->color_c = (color->flag << 16);
	}
	else
	{
		ft_putstr_fd("Error\ncelling color error\n", 2);
		exit(0);
	}
}

static void			ps_cl_color_three(t_color *color, t_vars *vars, char *str)
{
	while (str[color->count_str] == ' ')
		color->count_str++;
	if (ft_isdigit(str[color->count_str]))
	{
		color->flag = (ft_atoi(&str[color->count_str]));
		if (color->flag < 0 || color->flag > 255)
		{
			ft_putstr_fd("Error\ncelling color error\n", 2);
			exit(0);
		}
		while (ft_isdigit(str[color->count_str]))
			color->count_str++;
		vars->color_c += (color->flag << 8);
	}
	else
	{
		ft_putstr_fd("Error\ncelling color error\n", 2);
		exit(0);
	}
}

void				pars_ceilling_color(t_vars *vars, char *str)
{
	t_color		color;

	init_struct(&color);
	while (str[color.count_str] != '\0')
	{
		ps_cl_color_two(&color, vars, str);
		ps_cl_color_res(&color, str);
		ps_cl_color_three(&color, vars, str);
		ps_cl_color_res(&color, str);
		ps_cl_color_five(&color, vars, str);
		while (str[color.count_str] == ' ')
			color.count_str++;
		if (str[color.count_str] != ' ' && str[color.count_str] != '\0')
		{
			ft_putstr_fd("Error\ncelling color error\n", 2);
			exit(0);
		}
	}
}
