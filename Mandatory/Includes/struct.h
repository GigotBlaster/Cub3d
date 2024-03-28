/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:45:52 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/28 11:50:52 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_map
{
	char	**grid;
	char	*n_texture_path;
	char	*s_texture_path;
	char	*e_texture_path;
	char	*w_texture_path;
	char	*c_color;
	char	*f_color;

	int		c_color_int;
	int		f_color_int;
	int		width;
	int		height;
	//char	**map;

}	t_map;


typedef struct s_lst
{
	char			*mapline;
	struct s_lst	*next;
}t_lst;


typedef struct s_env
{
	t_map	*map;
}	t_env;

typedef struct s_player
{
	int		x;
	int		y;
}	t_player;



typedef struct s_image
{
	void	*img;
	int		*address;
	int		bits_by_pix;
	int		line_lengh_pix;
	int		endian;
	int		width;
	int		height;
}t_image;


typedef struct s_ray
{
	int			hit;
	int			side;
	int			step[2];
	int			map[2];
	float		pos[2];
	float		dir[2];
	float		plan[2];
	float		raydir[2];
	float		ray_side[2];
	float		delta[2];
	float		cam_x;
	float		texture_dist;
	float		height_l;
	float		draw_start;
	float		draw_end;
}t_ray;


typedef struct s_textures
{
	int			dir_text;
	int			tex_x;
	int			tex_y;
	double		wall_x;
	double		step;
	double		tex_pos;
}	t_textures;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*window_ptr;
	int			moves;
	int			m_moves_struc;
	char		direction;
	double		player[MAX_POS];
	double		speed;
	t_image		img[MAX_IMG];
	t_map		map;
	t_ray		ray;
	t_textures	textures;
}	t_data;

#endif
