/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:50:53 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/13 12:34:48 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_move_up(t_data *game)
{
	if (game->map.map[game->p_pos.y - 1][game->p_pos.x] != '1')
	{
		game->moves++;
		if (game->map.map[game->p_pos.y - 1][game->p_pos.x] == '0')
		{
			game->map.map[game->p_pos.y - 1][game->p_pos.x] = 'N';
			game->map.map[game->p_pos.y][game->p_pos.x] = '0';
			game->p_pos.y--;
		//	player_minimap(game);
		//	ft_render(game);
		}
	}
}

void	ft_move_down(t_data *game)
{
	if (game->map.map[game->p_pos.y + 1][game->p_pos.x] != '1')
	{
		game->moves++;
		if (game->map.map[game->p_pos.y + 1][game->p_pos.x] == '0')
		{
			game->map.map[game->p_pos.y + 1][game->p_pos.x] = 'N';
			game->map.map[game->p_pos.y][game->p_pos.x] = '0';
			game->p_pos.y++;
		//	player_minimap(game);

		//	ft_render(game);
		}
	}
}

void	ft_move_right(t_data *game)
{
	if (game->map.map[game->p_pos.y][game->p_pos.x + 1] != '1')
	{
		game->moves++;
		if (game->map.map[game->p_pos.y][game->p_pos.x + 1] == '0')
		{
			game->map.map[game->p_pos.y][game->p_pos.x + 1] = 'N';
			game->map.map[game->p_pos.y][game->p_pos.x] = '0';
			game->p_pos.x++;
		//	player_minimap(game);
		//	ft_render(game);
		}
	}
}

void	ft_move_left(t_data *game)
{
	if (game->map.map[game->p_pos.y][game->p_pos.x - 1] != '1')
	{
		game->moves++;
		if (game->map.map[game->p_pos.y][game->p_pos.x - 1] == '0')
		{
			game->map.map[game->p_pos.y][game->p_pos.x - 1] = 'N';
			game->map.map[game->p_pos.y][game->p_pos.x] = '0';
			game->p_pos.x--;
		//	player_minimap(game);
		//	ft_render(game);
		}
	}
}

void	ft_move(int key, t_data *game) //opti avec les bon code clavier ?
{
	// player_minimap(game);
	if (key == 'w' || key == KEY_UP)
		ft_move_up(game);
	else if (key == 's' || key == KEY_DOWN)
		ft_move_down(game);
	else if (key == 'd' || key == KEY_RIGHT)
	{
		game->direction = 'r';
		ft_move_right(game);
	}
	else if (key == 'a' || key == KEY_LEFT)
	{
		game->direction = 'l';
		ft_move_left(game);
	}
}


// void	move_player(t_data *game, char c)
// {
// 	double	new[2];

// 	if (c == 'W')
// 	{
// 		new[X] = ((new[Y] = d->ray.pos[Y] + (d->player_speed * d->ray.dir[Y]),
// 					d->ray.pos[X] + (d->player_speed * d->ray.dir[X])));
// 		if (d->map.map[(int)(d->ray.pos[Y] + d->ray.dir[Y] * 0.2)][(int)new[X]]
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
// 	if (d->map.map[(int)new[Y]][(int)new[X]] == '1')
// 		return ;
// 	update_pos(d, new);
// 	return ;
// }