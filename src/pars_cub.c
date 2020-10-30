/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 18:45:00 by hmiso             #+#    #+#             */
/*   Updated: 2020/09/23 18:51:29 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		pars_cub(char **argv, t_vars *vars)
{
	int		fd;
	char	*line;
	t_list	*tmp;

	line = NULL;
	tmp = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\ndid not find the file with the map\n", 2);
		exit(0);
	}
	while (get_next_line(fd, &line) > 0)
	{
		ft_lstadd_back(&tmp, ft_lstnew(line));
	}
	ft_lstadd_back(&tmp, ft_lstnew(line));
	vars->mas = save_map(ft_lstsize(tmp), &tmp);
}
