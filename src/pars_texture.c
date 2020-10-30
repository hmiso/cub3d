/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 10:38:12 by hmiso             #+#    #+#             */
/*   Updated: 2020/09/27 18:26:05 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void		init_variabels(int *count_str,
int *count_mas, char **reletiv_path, char *str2)
{
	*count_str = 0;
	*count_mas = 0;
	*reletiv_path = ft_strtrim(str2, " ");
}

static void		res_print_error(char *str)
{
	ft_putstr_fd("Error\ntexture error ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	exit(0);
}

void			pars_texture(t_vars *vars, char *str, char **adr, char *str2)
{
	int			count_mas;
	int			count_str;
	char		*reletiv_path;

	init_variabels(&count_str, &count_mas, &reletiv_path, str2);
	vars->text.img = mlx_xpm_file_to_image(vars->mlx,
	reletiv_path, &vars->text.widht, &vars->text.heith);
	if (vars->text.img == NULL)
		res_print_error(str);
	if (vars->text.widht != 64 || vars->text.heith != 64)
	{
		ft_putstr_fd("Error\nplease select textures 64 * 64 px - ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("\n", 2);
		exit(0);
	}
	*adr = mlx_get_data_addr(vars->text.img,
	&vars->text.bits_per_pixel, &vars->text.line_length, &vars->text.endian);
	if (*adr == NULL)
	{
		ft_putstr_fd("Error\nmallok pars_texture\n", 2);
		exit(0);
	}
	free(reletiv_path);
}
