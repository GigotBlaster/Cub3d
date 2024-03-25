/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:50:53 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/25 13:26:48 by npetitpi         ###   ########.fr       */
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

void	move_cam(t_data *game, double mouvmt)
{
	double	save_dir;
	double	save_plan;

	save_plan = game->ray.plan[X];
	save_dir = game->ray.dir[X];
	game->ray.dir[X] = game->ray.dir[X] * cos(mouvmt)
		- game->ray.dir[Y] * sin(mouvmt);
	game->ray.dir[Y] = save_dir * sin(mouvmt) + game->ray.dir[Y] * cos(mouvmt);
	game->ray.plan[X] = game->ray.plan[X] * cos(mouvmt)
		- game->ray.plan[Y] * sin(mouvmt);
	game->ray.plan[Y] = save_plan * sin(mouvmt) + game->ray.plan[Y] * cos(mouvmt);
}

// void	move_player(t_data *dir, char c)
// {
// 	double	new[2];

// 	if (c == 'W')
// 	{
// 		new[X] = ((new[Y] = dir->ray.pos[Y] + (dir->player_speed * dir->ray.dir[Y]),
// 					dir->ray.pos[X] + (dir->player_speed * dir->ray.dir[X])));
// 		if (dir->map.grid[(int)(dir->ray.pos[Y] + dir->ray.dir[Y] * 0.2)][(int)new[X]]
// 			== '1')
// 			return ;
// 	}
// 	else if (c == 'S')
// 		new[X] = ((new[Y] = dir->ray.pos[Y] - (dir->player_speed * dir->ray.dir[Y]),
// 					dir->ray.pos[X] - (dir->player_speed * dir->ray.dir[X])));
// 	else if (c == 'A')
// 		new[X] = ((new[Y] = dir->ray.pos[Y] - (dir->player_speed * dir->ray.dir[X]),
// 					dir->ray.pos[X] + (dir->player_speed * dir->ray.dir[Y])));
// 	else if (c == 'D')
// 		new[X] = ((new[Y] = dir->ray.pos[Y] + (dir->player_speed * dir->ray.dir[X]),
// 					dir->ray.pos[X] - (dir->player_speed * dir->ray.dir[Y])));
// 	if (dir->map.grid[(int)new[Y]][(int)new[X]] == '1')
// 		return ;
// 	update_pos(dir, new);
// 	return ;
// }

void	update_pos(t_data *game, double newpos[2])
{
	game->player[POS_X] = newpos[X];
	game->player[POS_Y] = newpos[Y];
	game->ray.pos[X] = newpos[X];
	game->ray.pos[Y] = newpos[Y];
}

