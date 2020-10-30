/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 19:43:28 by hmiso             #+#    #+#             */
/*   Updated: 2020/09/26 19:46:41 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		ft_close(void)
{
	exit(0);
}

void	print(t_vars *vars, char **argv)
{
	pars_cub(argv, vars);
	valid_mup_cub(vars);
	init_window(vars);
	pars_player(vars);
	pars_sprite(vars);
	print_player(vars);
	sort_sprite(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	mlx_hook(vars->win, 2, 0L, events, vars);
	mlx_hook(vars->win, 17, 0, ft_close, vars);
	mlx_loop(vars->mlx);
}

void	skrin(t_vars *vars, char **argv)
{
	pars_cub(argv, vars);
	valid_mup_cub(vars);
	init_window(vars);
	pars_player(vars);
	pars_sprite(vars);
	print_player(vars);
	sort_sprite(vars);
	skrinshot(vars);
}

void	chek_argv(int argc)
{
	if (argc < 2 || argc > 3)
	{
		ft_putstr_fd("Error\nWrong argument\n", 2);
		exit(0);
	}
}

int		main(int argc, char **argv)
{
	t_vars		vars;
	int			i;

	null_funk(&vars);
	vars.mlx = mlx_init();
	chek_argv(argc);
	i = ft_strlen(argv[1]);
	if (ft_strncmp(&argv[1][i - 4], ".cub", 5))
	{
		ft_putstr_fd("Error\nWrong format conf file\n", 2);
		exit(0);
	}
	if (argc == 3)
	{
		if (ft_strncmp(argv[2], "--save", 7) == 0)
			skrin(&vars, argv);
		else
		{
			ft_putstr_fd("Error\nWrong two argument\n", 2);
			exit(0);
		}
	}
	print(&vars, argv);
	return (0);
}
