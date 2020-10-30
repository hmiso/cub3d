/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 18:18:47 by hmiso             #+#    #+#             */
/*   Updated: 2020/09/27 18:15:32 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void		ps_sp_res(t_vars *vars, int *x, int *y)
{
	vars->mas_sprite[vars->count_sprite] = *x + 32;
	vars->count_sprite++;
	vars->mas_sprite[vars->count_sprite] = *y + 32;
	vars->count_sprite++;
}

static void		ps_sp_null(int *x, int *y, int *i, int *j)
{
	*x = 0;
	*y = 0;
	*i = 0;
	*j = 0;
}

static void		ps_sp_two(int *x, int *y, int *i, int *j)
{
	*x = 0;
	*i = 0;
	*j += 1;
	*y += 64;
}

static void		ps_sp_three(t_vars *vars)
{
	if (!vars->mas_sprite)
	{
		ft_putstr_fd("Error\nmallok pars_palyer\n", 2);
		exit(0);
	}
}

void			pars_sprite(t_vars *vars)
{
	int		x;
	int		y;
	int		i;
	int		j;

	ps_sp_null(&x, &y, &i, &j);
	if (vars->mas_sprite != NULL)
		free(vars->mas_sprite);
	vars->mas_sprite = malloc(sizeof(int) * vars->count_sprite * 2);
	ps_sp_three(vars);
	vars->count_sprite = 0;
	while (vars->mas[j] != NULL)
	{
		while (vars->mas[j][i] != '\0')
		{
			if (vars->mas[j][i] == '2')
				ps_sp_res(vars, &x, &y);
			x += 64;
			i++;
		}
		ps_sp_two(&x, &y, &i, &j);
	}
}
