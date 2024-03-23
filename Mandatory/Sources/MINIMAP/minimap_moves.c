/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:30:29 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/22 15:04:39 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub.h"

// void	player_minimap(t_data *game)
// {
//     // Player color : white
// 	int	player_color;
// 	int	minimap_x;
// 	int	minimap_y;

// 	player_color = 0xFFFFFF;
// Calculer les coordonnées sur la minimap (peut nécessiter une mise à l'échelle selon la taille de la fenêtre et de la carte)
// 	minimap_x = game->p_pos.x * SCALE_FACTOR_X; //ajuster a votre échelle
// 	minimap_y = game->p_pos.y * SCALE_FACTOR_Y; //ajuster a votre échelle

//     // Draw player on minimap
// 	mlx_pixel_put(game->mlx_ptr, game->window_ptr, minimap_x, minimap_y,
// 		player_color);
// }


///////////////////////////////////////////
void	map_to_minimap(t_data *game, int y, int x)
{
	if (y == (int)game->player[POS_Y] && x == (int)game->player[POS_X])
		print_box(game, y, x, 65025);
	else if (game->map.grid[y][x] == '1')
		print_box(game, y, x, 0);
	else if (game->map.grid[y][x] == '0')
		print_box(game, y, x, 16777215);
}

void	print_box(t_data *game, int y, int x, int color)
{
	int	i;
	int	j;

	j = 0;
	while (j < 10)
	{
		i = 0;
		while (i < 10)
		{
			game->img[VISU].address[(y * 10) * game->img[VISU].line_lengh_pix / 4
				+ (x * 10)] = color;
			game->img[VISU].address[(y * 10 + j) * game->img[VISU].line_lengh_pix / 4
				+ (x * 10)] = color;
			game->img[VISU].address[(y * 10 + j) * game->img[VISU].line_lengh_pix / 4
				+ (x * 10 + i)] = color;
			game->img[VISU].address[(y * 10) * game->img[VISU].line_lengh_pix / 4
				+ (x * 10 + i)] = color;
			i++;
		}
		j++;
	}
}
