/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:22:34 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/28 15:23:11 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_lst	*ft_lstnew(char *str)
{
	t_lst	*node;

	node = ft_calloc(1, sizeof(t_lst));
	if (!node)
		return (NULL);
	node->mapline = str;
	node->next = NULL;
	return (node);
}

t_lst	*ft_lstlast(t_lst *lst)
{
	t_lst	*last;

	last = lst;
	if (!lst)
		return (NULL);
	while (last->next)
		last = last->next;
	return (last);
}

int	ft_lstsize(t_lst *lst)
{
	t_lst	*last;
	int		i;

	i = 0;
	last = lst;
	if (!lst)
		return (0);
	while (last)
	{
		last = last->next;
		i++;
	}
	return (i);
}

