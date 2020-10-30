/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 19:14:58 by hmiso             #+#    #+#             */
/*   Updated: 2020/09/27 13:09:09 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*list;

	list = *lst;
	if (lst != NULL)
	{
		while (list)
		{
			tmp = list->next;
			(*del)(list->content);
			free(list);
			list = tmp;
		}
	}
	*lst = NULL;
}
