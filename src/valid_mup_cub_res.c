/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_mup_cub_res.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 18:39:58 by hmiso             #+#    #+#             */
/*   Updated: 2020/09/26 18:41:55 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int			vl_mup_rs(t_vars *vars, int c_s, int c_m, int *flag_mas)
{
	if (vars->mas[c_s][c_m] == 'R')
	{
		pars_skrin_size(vars, &vars->mas[c_s][c_m]);
		flag_mas[0]++;
		return (1);
	}
	else if (vars->mas[c_s][c_m] == 'N'
	&& vars->mas[c_s][c_m + 1] == 'O')
	{
		pars_texture(vars, "NO", &vars->text.addr_n,
		&vars->mas[c_s][c_m + 2]);
		flag_mas[1]++;
		return (1);
	}
	else if (vars->mas[c_s][c_m] == 'S'
	&& vars->mas[c_s][c_m + 1] == 'O')
	{
		pars_texture(vars, "SO", &vars->text.addr_s,
		&vars->mas[c_s][c_m + 2]);
		flag_mas[2]++;
		return (1);
	}
	return (0);
}

int			vl_mup_rs_two(t_vars *vars, int c_s, int c_m, int *flag_mas)
{
	if (vars->mas[c_s][c_m] == 'W' && vars->mas[c_s][c_m + 1] == 'E')
	{
		pars_texture(vars, "WE", &vars->text.addr_w,
		&vars->mas[c_s][c_m + 2]);
		flag_mas[3]++;
		return (1);
	}
	else if (vars->mas[c_s][c_m] == 'E' &&
	vars->mas[c_s][c_m + 1] == 'A')
	{
		pars_texture(vars, "EA", &vars->text.addr_e,
		&vars->mas[c_s][c_m + 2]);
		flag_mas[4]++;
		return (1);
	}
	else if (vars->mas[c_s][c_m] == 'S'
	&& (vars->mas[c_s][c_m + 1] == ' '
	|| vars->mas[c_s][c_m + 1] == '.'))
	{
		pars_texture(vars, "S", &vars->text.addr_spr,
		&vars->mas[c_s][c_m + 1]);
		flag_mas[5]++;
		return (1);
	}
	return (0);
}

int			vl_mup_rs_three(t_vars *vars, int c_s, int c_m, int *flag_mas)
{
	if (vars->mas[c_s][c_m] == 'F'
	&& (vars->mas[c_s][c_m + 1] == ' '
	|| ft_isdigit(vars->mas[c_s][c_m + 1])))
	{
		pars_flor_color(vars, &vars->mas[c_s][c_m + 1]);
		flag_mas[6]++;
		return (1);
	}
	else if (vars->mas[c_s][c_m] == 'C'
	&& (vars->mas[c_s][c_m + 1] == ' '
	|| ft_isdigit(vars->mas[c_s][c_m + 1])))
	{
		pars_ceilling_color(vars, &vars->mas[c_s][c_m + 1]);
		flag_mas[7]++;
		return (1);
	}
	else if (vars->mas[c_s][c_m] != ' '
	&& vars->mas[c_s][c_m] != '1'
	&& vars->mas[c_s][c_m] != '\0')
	{
		ft_putstr_fd("Error\nerror in resource files\n", 2);
		exit(0);
	}
	return (0);
}

void		vl_mup_rs_four(t_vars *vars, int c_s, int i, int *flag_start)
{
	while (vars->mas[c_s][i] != '\0')
	{
		if ((ft_strchr("20WSNE", vars->mas[c_s][i])) != NULL)
		{
			ft_putstr_fd("Error\nerror in map\n", 2);
			exit(0);
		}
		*flag_start = 1;
		i++;
	}
}

void		vl_mup_rs_five(t_vars *vars, int c_s, int c_m, int *flag_mas)
{
	while (vars->mas[c_s][c_m] != '\0')
	{
		if ((ft_strchr("120WSNE ", vars->mas[c_s][c_m])) == NULL)
		{
			ft_putstr_fd("Error\nerror in resource files\n", 2);
			exit(0);
		}
		if ((ft_strchr("120WSNE", vars->mas[c_s][c_m])) != NULL
		&& flag_mas[9] == 0)
		{
			flag_mas[9]++;
			valid_mup(vars, c_s, c_m);
		}
		if ((ft_strchr("WSNE", vars->mas[c_s][c_m])) != NULL)
			flag_mas[8]++;
		c_m++;
	}
}
