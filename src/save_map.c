/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 16:54:10 by hmiso             #+#    #+#             */
/*   Updated: 2020/09/27 18:33:23 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	print_error(void)
{
	ft_putstr_fd("Error\nmallok save_mup\n", 2);
	exit(0);
}

char		**save_map(int size, t_list **tmp)
{
	int		i;
	char	**map;
	t_list	*list;

	map = ft_calloc(size + 2, sizeof(char *));
	if (map == NULL)
		print_error();
	i = 0;
	list = *tmp;
	while (list)
	{
		map[i] = ft_strdup(list->content);
		if (map[i] == NULL)
			print_error();
		list = list->next;
		i++;
	}
	map[i] = ft_strdup("");
	map[i + 1] = NULL;
	ft_lstclear(tmp, free);
	return (map);
}
