/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:51:57 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/13 13:05:54 by npetitpi         ###   ########.fr       */
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

enum	e_player
{
	POS_Y,
	POS_X,
	MAX_POS,
};


# define SCREEN		"Window size too big"

#endif