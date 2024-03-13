/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:54:28 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/13 11:54:28 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_map *ft_map_init()
{
	t_map *map;
	
	map = (t_map *)malloc(sizeof(t_map));
	map->width = 0;
	map->height = 0;
	map->grid = NULL;
	map->n_texture_path = NULL;
	map->s_texture_path = NULL;
	map->e_texture_path = NULL;
	map->w_texture_path = NULL;
	map->c_color = NULL;
	map->f_color = NULL;
	return (map);
}

t_map *ft_fill_grid(t_env *env, const char *av)
{
	int i;
	int fd;
	char *buf;

	i = 0;
	fd = open(av, O_RDONLY);
	while ((buf = get_next_line(fd, 0)) != NULL)
	{
		if (buf[0] == '1')
			i++;
		free(buf);
	}
	close(fd);
	env->map->grid = ft_calloc(i + 1, sizeof(char*));
	i = 0;
	fd = open(av, O_RDONLY);
	while ((buf = get_next_line(fd, 0)) != NULL)
	{
		if (buf[0] == '1')
		{
			env->map->width = ft_strlen(buf);
			env->map->grid[i] = ft_calloc(env->map->width + 1, sizeof(char));
			ft_strcpy(env->map->grid[i++], buf);
		}
		free(buf);
	}
	close (fd);
	return (env->map);
}

void ft_free_map(t_map *map)
{
	int i;
	i = 0;
	while (map->grid[i])
		printf("%s\n", map->grid[i++]);
	i = 0;
	while (map->grid[i])
		free(map->grid[i++]);
	free(map->grid[i]);
	free(map->grid);
	free(map);
}