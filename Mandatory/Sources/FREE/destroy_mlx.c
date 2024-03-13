/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:20:13 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/13 13:22:38 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	destroy_all(t_data *game)
{
	if (game->window_ptr)
		mlx_destroy_window(game->mlx_ptr, game->window_ptr);
	if (game->mlx_ptr)
	{
		mlx_destroy_window(game->mlx_ptr, game->window_ptr);
		ft_free(game->mlx_ptr);
	}
}

