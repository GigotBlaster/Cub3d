/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:19:51 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/18 16:59:23 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_env	*ft_fill_texture(t_env *env, char *buf)
{
	if (buf[0] == 'N' && buf[1] == 'O')
	{
		buf += 3;
		env->map->n_texture_path = ft_strdup(buf);
		// printf("fill texture %s\n", env->map->n_texture_path);
	}
	else if (buf[0] == 'S' && buf[1] == 'O')
	{
		buf += 3;
		env->map->s_texture_path = ft_strdup(buf);
		// printf("fill texture %s\n", env->map->s_texture_path);
	}
	else if (buf[0] == 'W' && buf[1] == 'E')
	{
		buf += 3;
		env->map->w_texture_path = ft_strdup(buf);
		// printf("fill texture %s\n", env->map->w_texture_path);
	}
	else if (buf[0] == 'E' && buf[1] == 'A')
	{
		buf += 3;
		env->map->e_texture_path = ft_strdup(buf);
		// printf("fill texture %s\n", env->map->e_texture_path);
	}
	return (env);
}

int	ft_check_fill(t_env *env, char *buf)
{
	int		i;

	i = 0;
	if (buf[0] != '1')
		env = ft_fill_texture(env, buf);
	if (buf[0] == 'C' || buf[0] == 'F')
		env = ft_fill_colors(env, buf);
	if (buf[0] == '1')
		i++;
	return (free(buf), i);
}

t_map	*ft_fill_grid(t_env *env, const char *av)
{
	int		i;
	int		fd;
	char	*buf;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (NULL);
	buf = get_next_line(fd, 0);
	i = 0;
	while (buf != NULL)
	{
		i += ft_check_fill(env, buf);
		buf = get_next_line(fd, 0);
	}
	close(fd);
	env->map->grid = ft_calloc(i + 1, sizeof(char *));
	if (env->map->grid == NULL)
		return (NULL);
	fd = open(av, O_RDONLY);
	buf = get_next_line(fd, 0);
	i = 0;
	while (buf != NULL)
	{
		env = ft_copy_grid(env, buf, &i);
		buf = get_next_line(fd, 0);
	}
	return (close(fd), env->map);
}
