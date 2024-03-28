/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_mouse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 11:31:43 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/28 11:55:57 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub.h"

int	cam_mouse(int x, int y, t_data *game)
{
	double	m_move;

	(void) y;
	if (game->m_moves_struc == 10000)
	{
		game->m_moves_struc = x;
		return (0);
	}
	m_move = (game->m_moves_struc - x) * 0.01;
	move_cam(game, -m_move);
	game->m_moves_struc = x;
	return (0);
}

