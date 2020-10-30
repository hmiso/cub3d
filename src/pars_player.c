/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 18:13:52 by hmiso             #+#    #+#             */
/*   Updated: 2020/09/23 18:42:56 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void		pars_pl_res(t_vars *vars, int x, int y, double alfa)
{
	vars->x = x + 32;
	vars->y = y + 32;
	vars->alfa = alfa;
}

static void		pars_pl_two(int *x, int *y, int *i, int *j)
{
	*x = 0;
	*y = 0;
	*i = 0;
	*j = 0;
}

static void		pars_pl_three(int *x, int *y, int *i, int *j)
{
	*x = 0;
	*i = 0;
	*j += 1;
	*y += 64;
}

void			pars_player(t_vars *vars)
{
	int		x;
	int		y;
	int		i;
	int		j;

	pars_pl_two(&x, &y, &i, &j);
	while (vars->mas[j] != NULL)
	{
		while (vars->mas[j][i] != '\0')
		{
			if (vars->mas[j][i] == 'N')
				pars_pl_res(vars, x, y, 3 * M_PI / 2);
			if (vars->mas[j][i] == 'S')
				pars_pl_res(vars, x, y, M_PI_2);
			if (vars->mas[j][i] == 'E')
				pars_pl_res(vars, x, y, 0);
			if (vars->mas[j][i] == 'W')
				pars_pl_res(vars, x, y, M_PI);
			if (vars->mas[j][i] == '2')
				vars->count_sprite++;
			x += 64;
			i++;
		}
		pars_pl_three(&x, &y, &i, &j);
	}
}
