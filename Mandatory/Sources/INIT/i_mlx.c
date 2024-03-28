/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_mlx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:56:19 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/28 16:09:14 by npetitpi         ###   ########.fr       */
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

int	init_images(t_data *game)
{
	game->img[NORTH].img = mlx_xpm_file_to_image(game->mlx_ptr,
			game->map.n_texture_path, &game->img[NORTH].width,
			&game->img[NORTH].height);
	if (!game->img[NORTH].img)
		return (msg_error(game->map.n_texture_path, XPM, 1));
	game->img[SOUTH].img = mlx_xpm_file_to_image(game->mlx_ptr,
			game->map.s_texture_path, &game->img[SOUTH].width,
			&game->img[SOUTH].height);
	if (!game->img[SOUTH].img)
		return (msg_error(game->map.s_texture_path, XPM, 2));
	game->img[EAST].img = mlx_xpm_file_to_image(game->mlx_ptr,
			game->map.e_texture_path, &game->img[EAST].width,
			&game->img[EAST].height);
	if (!game->img[EAST].img)
		return (msg_error(game->map.e_texture_path, XPM, 3));
	game->img[WEST].img = mlx_xpm_file_to_image(game->mlx_ptr,
			game->map.w_texture_path, &game->img[WEST].width,
			&game->img[WEST].height);
	if (!game->img[WEST].img)
		return (msg_error(game->map.w_texture_path, XPM, 4));
	return (0);
}

int	init_textures(t_data *game)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		game->img[i].address = (int *)mlx_get_data_addr(game->img[i].img,
				&game->img[i].bits_by_pix, &game->img[i].line_lengh_pix,
				&game->img[i].endian);
		if (!game->img[i].address)
			return (1);
	}
	return (0);
}

int	visu(t_data *game)
{
	game->img[VISU].img = mlx_new_image(game->mlx_ptr, SCREEN_WIDTH,
			SCREEN_HEIGHT);
	if (!game->img[VISU].img)
		return (msg_error(NULL, INIT_IMG, 1));
	game->img[VISU].address = (int *)mlx_get_data_addr(game->img[VISU].img,
			&game->img[VISU].bits_by_pix, &game->img[VISU].line_lengh_pix,
			&game->img[VISU].endian);
	if (!game->img[VISU].address)
		return (msg_error(NULL, DATA_ADRESS, 2));
	return (0);
}

