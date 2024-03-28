/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:51:57 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/28 11:57:18 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define KEY_ESC		65307
# define KEY_UP			65362
# define KEY_DOWN		65364
# define KEY_LEFT		65361
# define KEY_RIGHT		65363
# define KEY_A			97
# define KEY_W			119
# define KEY_S			115
# define KEY_D			100

# define SCREEN_WIDTH	1024
# define SCREEN_HEIGHT	512
# define M_PI			3.14159265358979323846

# define X 1
# define Y 0


enum	e_player
{
	POS_Y,
	POS_X,
	POS_PXL_X,
	POS_PXL_Y,
	ANGLE,
	MAX_POS,
};

enum	e_img
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
	VISU,
	MAX_IMG,
};

# define SCREEN			"Window size too big"
# define NO_CUB			" : Need file .cub"
# define OPEN			" : OPEN failed"
# define NOT_XPM		" : is not a .xpm"
# define XPM			" : has failed to convert into xpm"
# define OPEN_TEXTURES	"Cannot open all the textures"
# define ARG_START		"Need 2 arguments"
# define INIT_IMG		"Init images failed (mlx_init_image)"
# define DATA_ADRESS	"Get data adress failed (mlx_get_data_addr)"
# define INIT_MLX		"mlx_init has failed"
# define SIZE_IMAGE		" : wrong size of image"
# define INV_MAP		"Invalid map"
# define MALLOC			"Malloc failed"
# define RGB			"Not a viable rgb"
# define WALLS			"The map isn't closed by wall"
# define NO_PLAYER		"No player in map"
# define TOO_PLAYER		"Too many players in map"


#endif