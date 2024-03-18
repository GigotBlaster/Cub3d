/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_to_null.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:38:29 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/18 13:52:23 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_to_null_game(t_data *game)
{
	game->mlx_ptr = NULL;
	game->window_ptr = NULL;
	game->player[POS_X] = 0;
	game->player[POS_Y] = 0;
	game->map.map = NULL;
	game->map.width = 0;
	game->map.height = 0;
	//game->player_speed = 0.1; //voir vitesse maybe trop arpide ?
}

t_map	*ft_map_init_null(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	map->width = 0;
	map->height = 0;
	map->grid = NULL;
	map->n_texture_path = NULL;
	map->s_texture_path = NULL;
	map->e_texture_path = NULL;
	map->w_texture_path = NULL;
	map->c_color = NULL;
	map->f_color = NULL;
	return (map);
}