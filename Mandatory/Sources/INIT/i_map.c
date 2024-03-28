/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:50:22 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/28 16:00:20 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub.h"

int	i_map(t_data *game, int fd)
{
	t_lst	*ltmap;
	t_lst	*tmp_map;
	int		a;

	ltmap = mapstore(fd);

	if (!ltmap)
		return (1);
	tmp_map = ltmap;
	while (tmp_map)
	{
		a = ft_strlen(tmp_map->mapline);
		if (path_store(game, tmp_map, a))
			break ;
		tmp_map = tmp_map->next;
	}
	if (check_path(game))
		return (free_all(game), free_map_lst(ltmap), msg_error(INV_MAP, NULL, 2));
	if (data_map_store(game, tmp_map) || dir_player(game, game->map.grid)
		|| check_data_map(game->map.grid))
		return (free_all(game), free_map_lst(ltmap),
			msg_error(INV_MAP, NULL, 1), 3);
	free_map_lst(ltmap);
	return (0);
}

t_lst	*mapstore(int fd)
{
	t_lst	*map_lst;
	t_lst	*tmp;
	char	*line;

	line = get_next_line(fd, 0);
	if (!line)
		return (msg_error(MALLOC, NULL, 1), NULL);
	tmp = ft_lstnew(line);
	map_lst = tmp;
	if (!tmp)
		return (msg_error(MALLOC, NULL, 2), NULL);
	while (line)
	{
		line = get_next_line(fd, 0);
		if (!line)
			break ;
		ft_lstlast(tmp)->next = ft_lstnew(line);
	}
	return (map_lst);
}

int	path_store(t_data *game, t_lst *ltmap, int a)
{
	if (!ltmap || !ltmap->mapline)
		return (1);
	if (ft_strncmp(ltmap->mapline, "NO ", 3))
	{
		if (game->map.n_texture_path)
			return (2);
		game->map.n_texture_path = ft_strndup((ltmap->mapline + 3), (a - 4));
		game->map.n_texture_path = ft_strtrim(game->map.n_texture_path, ' ');
	}
	else if (ft_strncmp(ltmap->mapline, "SO ", 3))
	{
		if (game->map.s_texture_path)
			return (2);
		game->map.s_texture_path = ft_strndup(ltmap->mapline + 3, (a - 4));
		game->map.s_texture_path = ft_strtrim(game->map.s_texture_path, ' ');
	}
	else
		return (path_store2(game, ltmap, a));
	return (0);
}

int	path_store2(t_data *game, t_lst *ltmap, int a)
{
	if (ft_strncmp(ltmap->mapline, "WE ", 3))
	{
		if (game->map.w_texture_path)
			return (2);
		game->map.w_texture_path = ft_strndup(ltmap->mapline + 3, (a - 4));
		game->map.w_texture_path = ft_strtrim(game->map.w_texture_path, ' ');
	}
	else if (ft_strncmp(ltmap->mapline, "EA ", 3))
	{
		if (game->map.e_texture_path)
			return (2);
		game->map.e_texture_path = ft_strndup(ltmap->mapline + 3, (a - 4));
		game->map.e_texture_path = ft_strtrim(game->map.e_texture_path, ' ');
	}
	else if (ft_strncmp(ltmap->mapline, "F ", 2))
	{
		if (game->map.f_color)
			return (2);
		game->map.f_color = ft_strndup(ltmap->mapline + 2, (a - 3));
		game->map.f_color = ft_strtrim(game->map.f_color, ' ');
	}
	else
		return (path_store3(game, ltmap, a));
	return (0);
}

int	path_store3(t_data *game, t_lst *ltmap, int a)
{
	if (ft_strncmp(ltmap->mapline, "C ", 2))
	{
		if (game->map.c_color)
			return (2);
		game->map.c_color = ft_strndup(ltmap->mapline + 2, (a - 3));
		game->map.c_color = ft_strtrim(game->map.c_color, ' ');
	}
	else if (ltmap->mapline[0] != '\n')
		return (3);
	return (0);
}