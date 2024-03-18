/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:15:29 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/18 13:51:09 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
	//free_tab(game->map.map, 0);
	destroy_all(game);
}

void	ft_free_map(t_map *map)
{
	int	i;

	i = 0;
	free(map->n_texture_path);
	free(map->s_texture_path);
	free(map->e_texture_path);
	free(map->w_texture_path);
	free(map->c_color);
	free(map->f_color);
	while (map->grid[i] != NULL)
	{
		// printf("%s", map->grid[i]);
		free(map->grid[i++]);
	}
	free(map->grid);
	free(map);
}