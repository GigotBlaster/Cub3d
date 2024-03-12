/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <lcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:45:52 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/12 14:15:13 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H


typedef struct s_map
{
	char **grid;
	char *n_texture_path;
	char *s_texture_path;
	char *e_texture_path;
	char *w_texture_path;

	char *c_color;
	char *f_color;

	int width;
	int height;

}	t_map;

typedef struct s_env
{
	t_map *map;
	
}	t_env;
typedef struct s_map
{
	char		**map;
}	t_map;

typedef struct s_player
{
	int		x;
	int		y;
}	t_player;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*window_ptr;
	int			moves;
	char		direction;
	t_player	p_pos;
	t_map		map;
}	t_data;


#endif
