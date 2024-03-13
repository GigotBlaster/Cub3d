/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_mlx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:56:19 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/13 13:12:03 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	check_screen_size(t_data *game)
{
	int	width;
	int	height;

	mlx_get_screen_size(game->mlx_ptr, &width, &height);
	if (SCREEN_WIDTH > width || SCREEN_HEIGHT > height)
		return (err_msg(SCREEN, NULL, 1));
	return (0);
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
	return (0);
}

