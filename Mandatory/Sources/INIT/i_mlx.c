/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_mlx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:56:19 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/23 11:47:47 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	check_screen_size(t_data *game)
{
	int	width;
	int	height;

	mlx_get_screen_size(game->mlx_ptr, &width, &height);
	if (SCREEN_WIDTH > width || SCREEN_HEIGHT > height)
		return (msg_error(SCREEN, NULL, 1));
	return (0);
}

void	init_pos_player(t_data *game)
{
	game->player[POS_X] += 0.5;
	game->player[POS_Y] += 0.5;
	game->player[POS_PXL_X] = game->player[POS_X] * 64;
	game->player[POS_PXL_Y] = game->player[POS_Y] * 64;
}

int	init_mlx(t_data *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		return (1);
	if (check_screen_size(game))
		return (2);
	game->window_ptr = mlx_new_window(game->mlx_ptr, SCREEN_WIDTH,
			SCREEN_HEIGHT, "My Wolfenstein");
	if (game->window_ptr == NULL)
		return (2);
	if (init_images(game))
		return (3);
	if (init_textures(game))
		return (4);
	if (visu(game))
		return (5);
	init_pos_player(game);
	game->ray.pos[X] = (double)game->player[POS_X];
	game->ray.pos[Y] = (double)game->player[POS_Y];
	return (0);
}
