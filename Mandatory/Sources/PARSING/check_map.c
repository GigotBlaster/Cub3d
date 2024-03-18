/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:03:58 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/18 13:50:06 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	map_ok(t_data *game, char *file)
{
	(void)game;
	int	fd;

	if (name_ok(file, ".cub"))
		return (err_msg(file, NO_CUB, 1));
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (err_msg(file, OPEN, 2));
	//init map
		//return (close(fd), 3);
	// Close fd
	//Check rgb???
		//return(ree_tab,free_path,err_msg(RGB, NULL, 4)
	// Check et open textures
		//return (free_ta,free_path,5);
	// Check wall 
		//return (free_tab,free_path,err_msg(WALLS, NULL, 6));
	return(0);
}

