/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_map2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:20:55 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/28 15:55:19 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub.h"

int	check_path(t_data *game)
{
	if (game->map.n_texture_path == NULL)
		return (1);
	else if (game->map.s_texture_path == NULL)
		return (1);
	else if (game->map.w_texture_path == NULL)
		return (1);
	else if (game->map.e_texture_path == NULL)
		return (1);
	else if (game->map.f_color == NULL)
		return (1);
	else if (game->map.c_color == NULL)
		return (1);
	return (0);
}

int	data_map_store(t_data *game, t_lst *stock_map)
{
	int		i;
	t_lst	*check;

	check = stock_map;
	if (check_char(check, stock_map))
		return (1);
	game->map.height = ft_lstsize(stock_map);
	game->map.grid = ft_calloc(game->map.height + 1, sizeof(char *));
	game->map.grid[game->map.height] = NULL;
	if (!game->map.grid)
		return (1);
	i = -1;
	while (stock_map)
	{
		if (stock_map->mapline[ft_strlen(stock_map->mapline) - 1] == '\n')
			stock_map->mapline[ft_strlen(stock_map->mapline) - 1] = '\0';
		game->map.grid[++i] = ft_strndup(stock_map->mapline,
				(ft_strlen(stock_map->mapline)));
		if (game->map.width < (ft_strlen(stock_map->mapline)))
			game->map.width = (ft_strlen(stock_map->mapline));
		if (!game->map.grid[i])
			return (1);
		stock_map = stock_map->next;
	}
	return (0);
}


void	set_value(t_data *game, char c, int i, int j)
{
	if (c == 'N')
	{
		game->ray.dir[X] = 0;
		game->ray.dir[Y] = -1;
		game->ray.plan[X] = 0.66;
		game->ray.plan[Y] = 0;
		game->player[ANGLE] = M_PI / 2;
	}
	else if (c == 'S')
	{
		game->ray.dir[X] = 0;
		game->ray.dir[Y] = 1;
		game->ray.plan[X] = -0.66;
		game->ray.plan[Y] = 0;
		game->player[ANGLE] = 1.5 * M_PI;
	}
	else
		set_value_2(game, c);
	game->player[POS_Y] = i;
	game->player[POS_X] = j;
}

void	set_value_2(t_data *game, char c)
{
	if (c == 'E')
	{
		game->ray.dir[X] = 1;
		game->ray.dir[Y] = 0;
		game->ray.plan[X] = 0;
		game->ray.plan[Y] = 0.66;
		game->player[ANGLE] = M_PI;
	}
	else if (c == 'W')
	{
		game->ray.dir[X] = -1;
		game->ray.dir[Y] = 0;
		game->ray.plan[X] = 0;
		game->ray.plan[Y] = -0.66;
		game->player[ANGLE] = 0;
	}
}

