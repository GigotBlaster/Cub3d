/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_player.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:45:13 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/28 15:47:08 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub.h"

void	init_pos_player(t_data *game)
{
	game->player[POS_X] += 0.5;
	game->player[POS_Y] += 0.5;
	game->player[POS_PXL_X] = game->player[POS_X] * 64;
	game->player[POS_PXL_Y] = game->player[POS_Y] * 64;
}


