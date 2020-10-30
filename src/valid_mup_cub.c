/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_mup_cub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 16:06:59 by hmiso             #+#    #+#             */
/*   Updated: 2020/09/26 18:40:44 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		vl_mup_rs_sixe(int *flag_mas)
{
	int	c_m;

	c_m = 0;
	while (c_m < 10)
	{
		if (flag_mas[c_m] != 1)
		{
			ft_putstr_fd("Error\nerror in resource files\n", 2);
			exit(0);
		}
		c_m++;
	}
}

void		init_variabls(int *c_s, int *c_m, int *flag_mas, int *flag_start)
{
	*c_s = 0;
	*c_m = 0;
	while (*c_m < 10)
	{
		flag_mas[*c_m] = 0;
		*c_m += 1;
	}
	*c_m = 0;
	*flag_start = 0;
}

int			vl_mup_rs_seven(int *c_s, int *c_m, int *flag_mas, t_vars *vars)
{
	if (vl_mup_rs(vars, *c_s, *c_m, flag_mas) == 1)
	{
		*c_s += 1;
		*c_m = 0;
		return (1);
	}
	else if (vl_mup_rs_two(vars, *c_s, *c_m, flag_mas) == 1)
	{
		*c_s += 1;
		*c_m = 0;
		return (1);
	}
	else if (vl_mup_rs_three(vars, *c_s, *c_m, flag_mas) == 1)
	{
		*c_s += 1;
		*c_m = 0;
		return (1);
	}
	return (0);
}

void		valid_mup_cub(t_vars *vars)
{
	int		c_s;
	int		c_m;
	int		flag_mas[10];
	int		flag_start;

	init_variabls(&c_s, &c_m, flag_mas, &flag_start);
	while (vars->mas[c_s] != NULL)
	{
		while (vars->mas[c_s][c_m] == ' ' && vars->mas[c_s][c_m] != '\0')
			c_m++;
		if (vl_mup_rs_seven(&c_s, &c_m, flag_mas, vars))
			continue;
		else if (vars->mas[c_s][c_m] == '1')
		{
			if (flag_start == 0)
				vl_mup_rs_four(vars, c_s, c_m, &flag_start);
			vl_mup_rs_five(vars, c_s, c_m, flag_mas);
		}
		c_m = 0;
		c_s++;
	}
	vl_mup_rs_sixe(flag_mas);
}
