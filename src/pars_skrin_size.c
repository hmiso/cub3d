/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_skrin_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 19:10:05 by hmiso             #+#    #+#             */
/*   Updated: 2020/09/27 09:45:41 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void		inint_structure(t_skrin *skrin)
{
	skrin->ptr = NULL;
	skrin->flag = 0;
	skrin->count_str = 1;
	skrin->count_mas = 0;
	skrin->x = 0;
	skrin->y = 0;
}

static void		resurse_ps_sk_won(t_skrin *skrin, char *mas)
{
	while (mas[skrin->count_str] == ' ')
		skrin->count_str++;
	if (ft_isdigit(mas[skrin->count_str]) && skrin->flag == 0)
	{
		skrin->x = ft_atoi(&mas[skrin->count_str]);
		while (ft_isdigit(mas[skrin->count_str]))
			skrin->count_str++;
		skrin->flag = 1;
	}
	if (mas[skrin->count_str] == ' ')
		skrin->count_str++;
	if (ft_isdigit(mas[skrin->count_str]) && skrin->flag == 1)
	{
		skrin->y = ft_atoi(&mas[skrin->count_str]);
		while (ft_isdigit(mas[skrin->count_str]))
			skrin->count_str++;
		skrin->flag = 2;
	}
	if (mas[skrin->count_str] == ' ')
		skrin->count_str++;
	if (mas[skrin->count_str] != ' ' && mas[skrin->count_str] != '\0')
	{
		ft_putstr_fd("Error\nerror in resolution\n", 2);
		exit(0);
	}
}

static void		resurse_ps_sk_two(t_vars *vars, t_skrin *skrin)
{
	vars->size_x = (int)skrin->x;
	vars->size_y = (int)skrin->y;
	mlx_get_screen_size(vars->mlx, &skrin->count_mas, &skrin->count_str);
	if ((int)vars->size_x > skrin->count_mas)
		vars->size_x = skrin->count_mas;
	if ((int)vars->size_y > skrin->count_str)
		vars->size_y = skrin->count_str;
}

void			pars_skrin_size(t_vars *vars, char *mas)
{
	t_skrin	skrin;

	inint_structure(&skrin);
	while (mas[skrin.count_str] != '\0')
		resurse_ps_sk_won(&skrin, mas);
	if (skrin.flag != 2)
	{
		ft_putstr_fd("Error\nerror in resolution\n", 2);
		exit(0);
	}
	if (skrin.x > 2147483647 || skrin.x < 0)
		skrin.x = 5000;
	if (skrin.y > 2147483647 || skrin.y < 0)
		skrin.y = 5000;
	if (skrin.x <= 99 || skrin.y <= 99)
	{
		ft_putstr_fd("Error\nvery small resolution at least 100 pixels\n", 2);
		exit(0);
	}
	resurse_ps_sk_two(vars, &skrin);
}
