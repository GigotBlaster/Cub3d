/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:20:13 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/23 12:05:23 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	destroy_img(t_data *game)
{
	if (game->img[CEILING].img)
		mlx_destroy_image(game->mlx_ptr, game->img[CEILING].img);
	game->img[CEILING].img = NULL;
	if (game->img[FLOOR].img)
		mlx_destroy_image(game->mlx_ptr, game->img[FLOOR].img);
	game->img[FLOOR].img = NULL;
	if (game->img[WALL_NORTH].img)
		mlx_destroy_image(game->mlx_ptr, game->img[WALL_NORTH].img);
	game->img[WALL_NORTH].img = NULL;
	if (game->img[WALL_SOUTH].img)
		mlx_destroy_image(game->mlx_ptr, game->img[WALL_SOUTH].img);
	game->img[WALL_SOUTH].img = NULL;
	if (game->img[WALL_EAST].img)
		mlx_destroy_image(game->mlx_ptr, game->img[WALL_EAST].img);
	game->img[WALL_EAST].img = NULL;
	if (game->img[WALL_WEST].img)
		mlx_destroy_image(game->mlx_ptr, game->img[WALL_WEST].img);
	game->img[WALL_WEST].img = NULL;
}


void	destroy_all(t_data *game)
{
	destroy_img(game);
	if (game->window_ptr)
		mlx_destroy_window(game->mlx_ptr, game->window_ptr);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		ft_free(game->mlx_ptr);
	}
}

