/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_to_null.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:38:29 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/13 13:29:46 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_to_null_game(t_data *game)
{
	game->mlx_ptr = NULL;
	game->window_ptr = NULL;
	game->player[POS_X] = 0;
	game->player[POS_Y] = 0;
	game->map.map = NULL;
	game->map.width = 0;
	game->map.height = 0;
}