/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:07:42 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/26 12:37:43 by npetitpi         ###   ########.fr       */
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

void	close_textures(int *fd)
{
	if (fd[0] != -1)
		close(fd[0]);
	if (fd[1] != -1)
		close(fd[1]);
	if (fd[2] != -1)
		close(fd[2]);
	if (fd[3] != -1)
		close(fd[3]);
}

int	check_open_textures(t_map img)
{
	int		fd[4];

	if (name_ok(img.n_texture_path, ".xpm"))
		return (msg_error("north", NOT_XPM, 1));
	else if (name_ok(img.s_texture_path, ".xpm"))
		return (msg_error("south", NOT_XPM, 1));
	else if (name_ok(img.e_texture_path, ".xpm"))
		return (msg_error("east", NOT_XPM, 1));
	else if (name_ok(img.w_texture_path, ".xpm"))
		return (msg_error("west", NOT_XPM, 1));
	fd[0] = open(img.n_texture_path, O_RDONLY);
	//printf("1---->%d\n", fd[0]);
	fd[1] = open(img.s_texture_path, O_RDONLY);
	//printf("2---->%d\n", fd[1]);
	fd[2] = open(img.e_texture_path, O_RDONLY);
	//printf("3---->%d\n", fd[2]);
	fd[3] = open(img.w_texture_path, O_RDONLY);
	//printf("4---->%d\n", fd[3]);
	if (fd[0] == -1 || fd[1] == -1 || fd[2] == -1 || fd[3] == -1)
		return (close_textures(fd), msg_error(OPEN_TEXTURES, NULL, 1));
	close_textures(fd);
	if (check_size_textures(img)) //a faire -> voir taille de chaque texture
		return (2);
	return (0);
}
