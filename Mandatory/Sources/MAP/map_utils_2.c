/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:19:36 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/26 16:34:58 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_env	*ft_copy_grid(t_env *env, char *buf, int *i)
{
	if (buf[0] == '1')
	{
		env->map->width = ft_strlen(buf);
		env->map->grid[*i] = ft_calloc(env->map->width + 1, sizeof(char));
		ft_strcpy(env->map->grid[(*i)++], buf);
	}
	return (free(buf), env);
}

t_env	*ft_fill_colors(t_env *env, char *buf)
{
	if (buf[0] == 'C')
	{
		buf += 2;
		env->map->c_color = ft_strdup(buf);
		// printf("fill colors -> c %s\n", env->map->c_color);
	}
	else
	{
		buf += 2;
		env->map->f_color = ft_strdup(buf);
		// printf("fill colors -> f %s\n", env->map->f_color);
	}
	return (env);
}

void ft_print_map(t_env *env)
{
	int i;

	i = 0;
	while (env->map->grid[i] != NULL)
		printf("%s", env->map->grid[i++]);
	printf("\nf color->%s", env->map->f_color);
	printf("c color->%s", env->map->c_color);
	printf("s->%s", env->map->s_texture_path);
	printf("n->%s", env->map->n_texture_path);
	printf("e->%s", env->map->e_texture_path);
	printf("w->%s\n", env->map->w_texture_path);
}
