/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:20:13 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/28 14:48:01 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	destroy_img(t_data *game)
{
	if (game->img[NORTH].img)
		mlx_destroy_image(game->mlx_ptr, game->img[NORTH].img);
	game->img[NORTH].img = NULL;
	if (game->img[SOUTH].img)
		mlx_destroy_image(game->mlx_ptr, game->img[SOUTH].img);
	game->img[SOUTH].img = NULL;
	if (game->img[EAST].img)
		mlx_destroy_image(game->mlx_ptr, game->img[EAST].img);
	game->img[EAST].img = NULL;
	if (game->img[WEST].img)
		mlx_destroy_image(game->mlx_ptr, game->img[WEST].img);
	game->img[WEST].img = NULL;
	mlx_destroy_image(game->mlx_ptr, game->img[VISU].img);
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

