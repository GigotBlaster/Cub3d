#include "cub.h"

t_env	*ft_copy_grid(t_env *env, char *buf, int *i)
{
	if (buf[0] == '1')
	{
		printf("%d\n", *i);
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