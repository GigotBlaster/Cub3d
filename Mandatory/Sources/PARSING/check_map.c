/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <lcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:03:58 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/18 16:26:36 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	map_ok(t_data *game, t_env *env,  char *file)
{
	(void)game;
	int	fd;

	if (name_ok(file, ".cub"))
		return (err_msg(file, NO_CUB, 1));
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (err_msg(file, OPEN, 2));
	env->map = ft_fill_grid(env, file);
	if (env->map == NULL)
		return (err_msg(file, "BAD MAP", 3));
	close(fd);
	ft_print_map(env);
	if (check_data_map(env->map->grid) == 1)
		return (err_msg(file, "BAD DATA MAP", 4));
		//return (free_tab,free_path,err_msg(WALLS, NULL, 6));
	return(0);
}

