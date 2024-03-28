/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:51:37 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/28 15:52:27 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub.h"

void	posi_cam(t_ray *ray, int screen_width, int x)
{
	ray->cam_x = 2.0 * x / (double)screen_width - 1;
	ray->raydir[X] = ray->dir[X] + ray->plan[X] * ray->cam_x;
	ray->raydir[Y] = ray->dir[Y] + ray->plan[Y] * ray->cam_x;
	ray->map[X] = (int)ray->pos[X];
	ray->map[Y] = (int)ray->pos[Y];
	ray->delta[X] = fabs(1 / ray->raydir[X]);
	ray->delta[Y] = fabs(1 / ray->raydir[Y]);
}

void	wall_lenght(t_ray *ray, int screen_height)
{
	if (ray->side == 0)
		ray->texture_dist = (ray->ray_side[X] - ray->delta[X]);
	else
		ray->texture_dist = (ray->ray_side[Y] - ray->delta[Y]);
	if (ray->texture_dist == 0)
		ray->texture_dist = 0.01;
	ray->height_l = (double)(screen_height / ray->texture_dist);
	ray->draw_start = (screen_height / 2) - (ray->height_l / 2);
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = (screen_height / 2) + (ray->height_l / 2);
	if (ray->draw_end >= screen_height)
		ray->draw_end = screen_height;
}

void	distance_btwn_ray_hv(t_ray *ray)
{
	if (ray->raydir[X] < 0)
		ray->ray_side[X] = (ray->pos[X] - ray->map[X]) * ray->delta[X];
	else
		ray->ray_side[X] = (ray->map[X] + 1.0 - ray->pos[X])
			* ray->delta[X];
	if (ray->raydir[Y] < 0)
		ray->ray_side[Y] = (ray->pos[Y] - ray->map[Y]) * ray->delta[Y];
	else
		ray->ray_side[Y] = (ray->map[Y] + 1.0 - ray->pos[Y])
			* ray->delta[Y];
	if (ray->raydir[X] < 0)
		ray->step[X] = -1;
	else
		ray->step[X] = 1;
	if (ray->raydir[Y] < 0)
		ray->step[Y] = -1;
	else
		ray->step[Y] = 1;
}


void	algo_dda(t_ray *ray, t_map *map)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		if (ray->ray_side[X] < ray->ray_side[Y])
		{
			ray->ray_side[X] += ray->delta[X];
			ray->map[X] += ray->step[X];
			ray->side = 0 ;
		}
		else
		{
			ray->ray_side[Y] += ray->delta[Y];
			ray->map[Y] += ray->step[Y];
			ray->side = 1 ;
		}
		if (map->grid[ray->map[Y]][ray->map[X]] == '1')
			ray->hit = 1;
	}
}

void	draw_wall(t_data *game, int x, t_ray *ray, t_textures *text)
{
	int	j;

	init_walls(ray, text);
	j = ray->draw_start;
	text->tex_x = (int)(text->wall_x * (float)game->img[text->dir_text].width);
	if (ray->side == 0 && ray->raydir[X] > 0)
		text->tex_x = game->img[text->dir_text].width - text->tex_x - 1;
	if (ray->side == 1 && ray->raydir[Y] < 0)
		text->tex_x = game->img[text->dir_text].width - text->tex_x - 1;
	text->step = 1.0 * game->img[text->dir_text].height / ray->height_l;
	text->tex_pos = (ray->draw_start - SCREEN_HEIGHT / 2 + \
		ray->height_l / 2) * text->step;
	while (j <= ray->draw_end)
	{
		text->tex_y = (int)text->tex_pos & (game->img[text->dir_text].height - 1);
		text->tex_pos += text->step;
		if (j < SCREEN_HEIGHT && x < SCREEN_WIDTH)
			game->img[VISU].address[j * game->img[VISU].line_lengh_pix / 4 + x]
				= game->img[text->dir_text].address[text->tex_y
				* game->img[text->dir_text].line_lengh_pix / 4 + text->tex_x];
		j++;
	}
}