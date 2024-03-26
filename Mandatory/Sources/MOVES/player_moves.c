/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:50:53 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/26 15:11:51 by npetitpi         ###   ########.fr       */
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
// 		game->++;
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



void	update_pos(t_data *game, double new_pos[2])
{
	game->player[POS_X] = new_pos[X];
	game->player[POS_Y] = new_pos[Y];
	game->ray.pos[X] = new_pos[X];
	game->ray.pos[Y] = new_pos[Y];
}


// void move_forward(t_data *game, double speed) {
//     // Vérifier si la nouvelle position en X est accessible (pas de mur)
//     if (game->map.grid[(int)(game->ray.pos[Y])]
//                       [(int)(game->ray.pos[X] + game->ray.dir[X] * speed)] == '0') {
//         game->ray.pos[X] += game->ray.dir[X] * speed;
//     }
//     // Vérifier si la nouvelle position en Y est accessible (pas de mur)
//     if (game->map.grid[(int)(game->ray.pos[Y] + game->ray.dir[Y] * speed)]
//                       [(int)(game->ray.pos[X])] == '0') {
//         game->ray.pos[Y] += game->ray.dir[Y] * speed;
//     }
// }

void	motion(t_data *move, char key)
{
	double	new_pos[2];

	if (key == 'W')
	{
		new_pos[X] = ((new_pos[Y] = move->ray.pos[Y] + (move->speed * move->ray.dir[Y]),
					move->ray.pos[X] + (move->speed * move->ray.dir[X])));
		if (move->map.grid[(int)(move->ray.pos[Y] + move->ray.dir[Y] * 0.2)][(int)new_pos[X]]
			== '1')
			return ;
	}
	else if (key == 'S')
		new_pos[X] = ((new_pos[Y] = move->ray.pos[Y] - (move->speed * move->ray.dir[Y]),
					move->ray.pos[X] - (move->speed * move->ray.dir[X])));
	else if (key == 'A')
		new_pos[X] = ((new_pos[Y] = move->ray.pos[Y] - (move->speed * move->ray.dir[X]),
					move->ray.pos[X] + (move->speed * move->ray.dir[Y])));
	else if (key == 'D')
		new_pos[X] = ((new_pos[Y] = move->ray.pos[Y] + (move->speed * move->ray.dir[X]),
					move->ray.pos[X] - (move->speed * move->ray.dir[Y])));
	if (move->map.grid[(int)new_pos[Y]][(int)new_pos[X]] == '1')
		return ;
	update_pos(move, new_pos);
	return ;
}
