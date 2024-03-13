/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:15:29 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/13 13:26:33 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	ft_free(void *adress)
{
	if (adress)
		free(adress);
	adress = NULL;
}

void	free_tab(char **tab, int n)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i] && (i < n || n == 0))
	{
		ft_free(tab[i]);
		i++;
	}
	ft_free(tab);
}

void	free_all(t_data *game)
{
	free_tab(game->map.map, 0);
	destroy_all(game);
}

