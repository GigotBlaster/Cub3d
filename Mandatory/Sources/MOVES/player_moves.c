/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:50:53 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/23 14:30:09 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// void	ft_move_player(t_data *game, char c)
// {
// 	double	new[2];

// 	if (c == 'W')
// 	{
// 		new[X] = game->p_pos.x;
// 		new[Y] = game->p_pos.y - game->player_speed;
// 	}
// 	else if (c == 'S')
// 	{
// 		new[X] = game->p_pos.x;
// 		new[Y] = game->p_pos.y + game->player_speed;
// 	}
// 	else if (c == 'A')
// 	{
// 		new[X] = game->p_pos.x - game->player_speed;
// 		new[Y] = game->p_pos.y;
// 	}
// 	else if (c == 'D')
// 	{
// 		new[X] = game->p_pos.x + game->player_speed;
// 		new[Y] = game->p_pos.y;
// 	}

// 	if (game->map.grid[(int)new[Y]][(int)new[X]] != '1')
// 	{
// 		game->moves++;
// 		if (game->map.grid[(int)new[Y]][(int)new[X]] == '0')
// 		{
// 			game->map.grid[(int)new[Y]][(int)new[X]] = 'N';
// 			game->map.grid[game->p_pos.y][game->p_pos.x] = '0';
// 			game->p_pos.x = (int)new[X];
// 			game->p_pos.y = (int)new[Y];
// 		}
// 	}
// }



// void	ft_move_up(t_data *game)
// {
// 	if (game->map.map[game->p_pos.y - 1][game->p_pos.x] != '1')
// 	{
// 		game->moves++;
// 		if (game->map.map[game->p_pos.y - 1][game->p_pos.x] == '0')
// 		{
// 			game->map.map[game->p_pos.y - 1][game->p_pos.x] = 'N';
// 			game->map.map[game->p_pos.y][game->p_pos.x] = '0';
// 			game->p_pos.y--;
// 		//	player_minimap(game);
// 		//	ft_render(game);
// 		}
// 	}
// }

// void	ft_move_down(t_data *game)
// {
// 	if (game->map.map[game->p_pos.y + 1][game->p_pos.x] != '1')
// 	{
// 		game->moves++;
// 		if (game->map.map[game->p_pos.y + 1][game->p_pos.x] == '0')
// 		{
// 			game->map.map[game->p_pos.y + 1][game->p_pos.x] = 'N';
// 			game->map.map[game->p_pos.y][game->p_pos.x] = '0';
// 			game->p_pos.y++;
// 		//	player_minimap(game);
// 		//	ft_render(game);
// 		}
// 	}
// }

// void	ft_move_right(t_data *game)
// {
// 	if (game->map.map[game->p_pos.y][game->p_pos.x + 1] != '1')
// 	{
// 		game->moves++;
// 		if (game->map.map[game->p_pos.y][game->p_pos.x + 1] == '0')
// 		{
// 			game->map.map[game->p_pos.y][game->p_pos.x + 1] = 'N';
// 			game->map.map[game->p_pos.y][game->p_pos.x] = '0';
// 			game->p_pos.x++;
// 		//	player_minimap(game);
// 		//	ft_render(game);
// 		}
// 	}
// }

// void	ft_move_left(t_data *game)
// {
// 	if (game->map.map[game->p_pos.y][game->p_pos.x - 1] != '1')
// 	{
// 		game->moves++;
// 		if (game->map.map[game->p_pos.y][game->p_pos.x - 1] == '0')
// 		{
// 			game->map.map[game->p_pos.y][game->p_pos.x - 1] = 'N';
// 			game->map.map[game->p_pos.y][game->p_pos.x] = '0';
// 			game->p_pos.x--;
// 		//	player_minimap(game);
// 		//	ft_render(game);
// 		}
// 	}
// }

// void	ft_move(int key, t_data *game) //opti avec les bon code clavier ?
// {
// 	// player_minimap(game);
// 	if (key == 'w' || key == KEY_UP)
// 		ft_move_up(game);
// 	else if (key == 's' || key == KEY_DOWN)
// 		ft_move_down(game);
// 	else if (key == 'd' || key == KEY_RIGHT)
// 	{
// 		game->direction = 'r';
// 		ft_move_right(game);
// 	}
// 	else if (key == 'a' || key == KEY_LEFT)
// 	{
// 		game->direction = 'l';
// 		ft_move_left(game);
// 	}
// }



//???Check Princesse

// void	move_cam(t_data *data, double mouv)
// {
// 	double	save_dir;
// 	double	save_plan;

// 	save_dir = data->ray.dir[X];
// 	save_plan = data->ray.plan[X];
// 	data->ray.dir[X] = data->ray.dir[X] * cos(mouv)
// 		- data->ray.dir[Y] * sin(mouv);
// 	data->ray.dir[Y] = save_dir * sin(mouv) + data->ray.dir[Y] * cos(mouv);
// 	data->ray.plan[X] = data->ray.plan[X] * cos(mouv)
// 		- data->ray.plan[Y] * sin(mouv);
// 	data->ray.plan[Y] = save_plan * sin(mouv) + data->ray.plan[Y] * cos(mouv);
// }

// void	move_player(t_data *d, char c)
// {
// 	double	new[2];

// 	if (c == 'W')
// 	{
// 		new[X] = ((new[Y] = d->ray.pos[Y] + (d->player_speed * d->ray.dir[Y]),
// 					d->ray.pos[X] + (d->player_speed * d->ray.dir[X])));
// 		if (d->map.grid[(int)(d->ray.pos[Y] + d->ray.dir[Y] * 0.2)][(int)new[X]]
// 			== '1')
// 			return ;
// 	}
// 	else if (c == 'S')
// 		new[X] = ((new[Y] = d->ray.pos[Y] - (d->player_speed * d->ray.dir[Y]),
// 					d->ray.pos[X] - (d->player_speed * d->ray.dir[X])));
// 	else if (c == 'A')
// 		new[X] = ((new[Y] = d->ray.pos[Y] - (d->player_speed * d->ray.dir[X]),
// 					d->ray.pos[X] + (d->player_speed * d->ray.dir[Y])));
// 	else if (c == 'D')
// 		new[X] = ((new[Y] = d->ray.pos[Y] + (d->player_speed * d->ray.dir[X]),
// 					d->ray.pos[X] - (d->player_speed * d->ray.dir[Y])));
// 	if (d->map.grid[(int)new[Y]][(int)new[X]] == '1')
// 		return ;
// 	update_pos(d, new);
// 	return ;
// }

// void	update_pos(t_data *data, double newpos[2])
// {
// 	data->player[POS_X] = newpos[X];
// 	data->player[POS_Y] = newpos[Y];
// 	data->ray.pos[X] = newpos[X];
// 	data->ray.pos[Y] = newpos[Y];
// }

