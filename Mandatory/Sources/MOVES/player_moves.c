/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:50:53 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/28 16:18:05 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"


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

void	update_pos(t_data *game, double new_pos[2])
{
	game->player[POS_X] = new_pos[X];
	game->player[POS_Y] = new_pos[Y];
	game->ray.pos[X] = new_pos[X];
	game->ray.pos[Y] = new_pos[Y];
}

