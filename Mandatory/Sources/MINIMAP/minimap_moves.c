/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <lcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:30:29 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/26 16:45:39 by lcadinot         ###   ########.fr       */
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
// 	minimap_x = game->p_pos.x * SCALE_FACTOR_X; //ajuster a votre échelle
// 	minimap_y = game->p_pos.y * SCALE_FACTOR_Y; //ajuster a votre échelle

//     // Draw player on minimap
// 	mlx_pixel_put(game->mlx_ptr, game->window_ptr, minimap_x, minimap_y,
// 		player_color);
// }



void	map_to_minimap(t_data *game, int x, int y)
{
	if (x == (int)game->player[POS_Y] && y == (int)game->player[POS_X])
		print_minimap(game, x, y, 60000);
	else if (game->map.grid[x][y] == '1')
		print_minimap(game, x, y, 0);
	else if (game->map.grid[x][y] == '0')
		print_minimap(game, x, y, 16777215);
}

void	print_minimap(t_data *game, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			game->img[VISU].address[(x * 8) * game->img[VISU].line_lengh_pix / 4
				+ (y * 8)] = color;
			game->img[VISU].address[(x * 8 + i) * game->img[VISU].line_lengh_pix / 4
				+ (y * 8)] = color;
			game->img[VISU].address[(x * 8 + i) * game->img[VISU].line_lengh_pix / 4
				+ (y * 8 + j)] = color;
			game->img[VISU].address[(x * 8) * game->img[VISU].line_lengh_pix / 4
				+ (y * 8 + j)] = color;
			j++;
		}
		i++;
	}
}
