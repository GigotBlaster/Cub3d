/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:03:58 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/28 16:43:45 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	map_ok(t_data *game,  char *file)
{
	int	fd;

	if (name_ok(file, ".cub"))
		return (msg_error(file, NO_CUB, 1));
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (msg_error(file, OPEN, 2));
	if (i_map(game, fd))
		return (close(fd), 3);
	close(fd);
	if (rgb(game))
		return (free_tab(game->map.grid, 0), free_img(game->map),
			msg_error(RGB, NULL, 4));
	if (check_open_textures(game->map))
		return (free_tab(game->map.grid, 0), free_img(game->map), 5);
	if (check_wall(game->map.grid))
		return (free_tab(game->map.grid, 0), free_img(game->map),
			msg_error(WALLS, NULL, 6));
	return (0);
}

int	name_ok(char *file, char *str) //ok
{
	int	len;

	len = ft_strlen(file);
	if (file[len - 4] != str[0] || file[len - 3] != str[1]
		|| file[len - 2] != str[2] || file[len - 1] != str[3])
		return (1);
	return (0);
}


int	check_around(char **map, int y, int x)
{
	if (x + 1 >= ft_strlen(map[y]) && (map[y][x + 1] != '1'
		&& map[y][x + 1] != '0'))
		return (1);
	else if (x - 1 < 0 || ((map[y][x - 1] != '1' && map[y][x - 1] != '0')))
		return (1);
	else if (x >= ft_strlen(map[y + 1])
		|| (map[y + 1][x] != '1'
		&& map[y + 1][x] != '0'))
		return (1);
	else if ((x > ft_strlen(map[y - 1])
			|| (map[y - 1][x] != '1' && map[y - 1][x] != '0')))
		return (1);
	return (0);
}


int	check_wall(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '0')
				if (check_around(map, y, x))
					return (1);
			x++;
		}
		y++;
	}
	return (0);
}


