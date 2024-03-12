/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:08:47 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/12 12:54:53 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

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