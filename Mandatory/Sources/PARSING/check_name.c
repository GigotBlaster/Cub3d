/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:07:42 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/18 13:54:49 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	name_ok(char *file, char *str) //ok
{
	int	len;

	len = ft_strlen(file);
	if (file[len - 4] != str[0] || file[len - 3] != str[1] 
		|| file[len - 2] != str[2] || file[len - 1] != str[3])
		return (1);
	return (0);
}


//1er JET A TESTER AVEC IMAGES

// void	close_textures(int *fd)
// {
// 	if (fd[0] != -1)
// 		close(fd[0]);
// 	if (fd[1] != -1)
// 		close(fd[1]);
// 	if (fd[2] != -1)
// 		close(fd[2]);
// 	if (fd[3] != -1)
// 		close(fd[3]);
// }

// int	check_open(t_map img)
// {
// 	int		fd[4];

// 	if (check_ext(img.n_texture_path, ".xpm"))
// 		return (err_msg("North", NOT_XPM, 1));
// 	else if (check_ext(img.s_texture_path, ".xpm"))
// 		return (err_msg("South", NOT_XPM, 1));
// 	else if (check_ext(img.w_texture_path, ".xpm"))
// 		return (err_msg("West", NOT_XPM, 1));
// 	else if (check_ext(img.e_texture_path, ".xpm"))
// 		return (err_msg("East", NOT_XPM, 1));
// 	fd[0] = open(img.n_texture_path, O_RDONLY);
// 	fd[1] = open(img.s_texture_path, O_RDONLY);
// 	fd[2] = open(img.w_texture_path, O_RDONLY);
// 	fd[3] = open(img.e_texture_path, O_RDONLY);
// 	if (fd[0] == -1 || fd[1] == -1 || fd[2] == -1 || fd[3] == -1)
// 		return (close_txtures(fd), err_msg(OPEN_TEXTURES, NULL, 1));
// 	close_txtures(fd);
// 	// if (check_textures_size(img)) //a faire -> voir taille de chaque texture
// 		// 	return (2);
// 	return (0);
// }