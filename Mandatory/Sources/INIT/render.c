/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:50:41 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/28 16:41:51 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub.h"

int	render(t_data *game)
{
	int	x;
	int	y;

	x = 0;
	print_back(game);
	raycasting(game);
	while (game->map.grid[x])
	{
		y = 0;
		while (game->map.grid[x][y])
		{
			map_to_minimap(game, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(game-> mlx_ptr, game->window_ptr, game->img[VISU].img, 0, 0);
	return (0);
}

void	print_back(t_data *game)
{
	int	j;
	int	i;

	j = 0;
	while (j < SCREEN_HEIGHT / 2)
	{
		i = -1;
		while (++i < SCREEN_WIDTH)
			game->img[VISU].address[j * game->img[VISU].line_lengh_pix / 4 + i]
				= game->map.c_color_int;
		j++;
	}
		//printf("%d\n", game->img[VISU].address[j * game->img[VISU].line_lengh_pix / 4 + i]);
	while (j < SCREEN_HEIGHT)
	{
		i = -1;
		while (++i < SCREEN_WIDTH)
			game->img[VISU].address[j * game->img[VISU].line_lengh_pix / 4 + i]
				= game->map.f_color_int;
		j++;
	}
}

void	raycasting(t_data *game)
{
	int	x;

	print_back(game);
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		posi_cam(&game->ray, SCREEN_WIDTH, x);
		distance_btwn_ray_hv(&game->ray);
		algo_dda(&game->ray, &game->map);
		wall_lenght(&game->ray, SCREEN_HEIGHT);
		draw_wall(game, x, &game->ray, &game->textures);
		x++;
	}
}

void	init_walls(t_ray *ray, t_textures *texture)
{
	if (ray->side == 0 && ray->raydir[X] < 0)
		texture->dir_text = 0;
	if (ray->side == 0 && ray->raydir[X] > 0)
		texture->dir_text = 1;
	if (ray->side == 1 && ray->raydir[Y] < 0)
		texture->dir_text = 2;
	if (ray->side == 1 && ray->raydir[Y] > 0)
		texture->dir_text = 3;
	if (ray->side == 0)
		texture->wall_x = ray->pos[Y] + ray->texture_dist * ray->raydir[Y];
	else
		texture->wall_x = ray->pos[X] + ray->texture_dist * ray->raydir[X];
	texture->wall_x -= floor(texture->wall_x);
}

