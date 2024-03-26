/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_textures.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <lcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:45:20 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/26 14:41:47 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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

