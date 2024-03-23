/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_to_null.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:38:29 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/23 13:11:21 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// t_map	*ft_map_init_null(void)
// {
// 	t_map	*map;

// 	map = (t_map *)malloc(sizeof(t_map));
// 	map->width = 0;
// 	map->height = 0;
// 	map->grid = NULL;
// 	return (map);
// }

void	init_to_null_textures(t_data *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		game->img[i].address = NULL;
		game->img[i].img = NULL;
		game->img[i].endian = 0;
		game->img[i].bits_by_pix = 0;
		i++;
	}
}

void	init_to_null_images(t_data *game)
{
	game->map.n_texture_path = NULL;
	game->map.s_texture_path = NULL;
	game->map.e_texture_path = NULL;
	game->map.w_texture_path = NULL;
	game->map.c_color = NULL;
	game->map.f_color = NULL;
}

void	init_to_null_game(t_data *game)
{
	game->mlx_ptr = NULL;
	game->window_ptr = NULL;
	game->map.grid = NULL;  //change
	game->player[POS_X] = 0;
	game->player[POS_Y] = 0;
	//game->player_speed = 0.1; //voir vitesse maybe trop arpide ?
	game->map.c_color_int = 0;
	game->map.f_color_int = 0;
	init_to_null_images(game);
	init_to_null_textures(game);
}
