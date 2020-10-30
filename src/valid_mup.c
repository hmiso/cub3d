/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_mup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 01:24:00 by hmiso             #+#    #+#             */
/*   Updated: 2020/09/26 01:35:39 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	res_val_mp(int count_str, int count_mas, t_vars *vars)
{
	if (count_str == 0)
	{
		ft_putstr_fd("Error\nmap error\n", 2);
		exit(0);
	}
	if (vars->mas[count_mas][count_str + 1] == ' '
	|| vars->mas[count_mas][count_str - 1] == ' '
	|| vars->mas[count_mas + 1][count_str] == ' '
	|| vars->mas[count_mas - 1][count_str] == ' '
	|| vars->mas[count_mas][count_str + 1] == '\0'
	|| vars->mas[count_mas][count_str - 1] == '\0'
	|| vars->mas[count_mas + 1][count_str] == '\0'
	|| vars->mas[count_mas - 1][count_str] == '\0'
	|| (int)ft_strlen(vars->mas[count_mas - 1]) < count_str
	|| (vars->mas[count_mas + 1] != NULL
	&& (int)ft_strlen(vars->mas[count_mas + 1]) < count_str))
	{
		ft_putstr_fd("Error\nmap error\n", 2);
		exit(0);
	}
}

void		valid_mup(t_vars *vars, int count_mas, int count_str)
{
	while (vars->mas[count_mas] != NULL)
	{
		while (vars->mas[count_mas][count_str] != '\0')
		{
			if (vars->mas[count_mas][count_str] == '1'
			|| vars->mas[count_mas][count_str] == '0'
			|| vars->mas[count_mas][count_str] == '2'
			|| ft_strchr("NSWE", vars->mas[count_mas][count_str])
			|| vars->mas[count_mas][count_str] == ' ')
			{
				if (vars->mas[count_mas][count_str] == '0'
				|| vars->mas[count_mas][count_str] == '2'
				|| ft_strchr("NSWE", vars->mas[count_mas][count_str]))
					res_val_mp(count_str, count_mas, vars);
			}
			else
			{
				ft_putstr_fd("Error\nmap error\n", 2);
				exit(0);
			}
			count_str++;
		}
		count_str = 0;
		count_mas++;
	}
}
