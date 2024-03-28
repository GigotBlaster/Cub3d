/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:16:41 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/28 16:22:36 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub.h"


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
	fd[1] = open(img.s_texture_path, O_RDONLY);
	fd[2] = open(img.e_texture_path, O_RDONLY);
	fd[3] = open(img.w_texture_path, O_RDONLY);
	if (fd[0] == -1 || fd[1] == -1 || fd[2] == -1 || fd[3] == -1)
		return (close_textures(fd), msg_error(OPEN_TEXTURES, NULL, 1));
	close_textures(fd);
	if (check_size_textures(img))
		return (2);
	return (0);
}

int	check_size_textures(t_map img)
{
	void	*ptr_img;
	void	*mlx;

	mlx = mlx_init();
	if (!mlx)
		return (msg_error(INIT_MLX, NULL, 1));
	ptr_img = NULL;
	if (to_size(mlx, ptr_img, img.n_texture_path))
		return (mlx_destroy_display(mlx), ft_free(mlx),
			msg_error(img.n_texture_path, SIZE_IMAGE, 1));
	if (to_size(mlx, ptr_img, img.s_texture_path))
		return (mlx_destroy_display(mlx), ft_free(mlx),
			msg_error(img.s_texture_path, SIZE_IMAGE, 1));
	if (to_size(mlx, ptr_img, img.e_texture_path))
		return (mlx_destroy_display(mlx), ft_free(mlx),
			msg_error(img.e_texture_path, SIZE_IMAGE, 1));
	if (to_size(mlx, ptr_img, img.w_texture_path))
		return (mlx_destroy_display(mlx), ft_free(mlx),
			msg_error(img.w_texture_path, SIZE_IMAGE, 1));
	mlx_destroy_display(mlx);
	ft_free(mlx);
	return (0);
}

int	to_size(void *mlx, void *ptr_img, char *map)
{
	int	height;
	int	width;

	height = 0;
	width = 0;
	ptr_img = mlx_xpm_file_to_image(mlx, map, &height, &width);
	if (!ptr_img)
		return (1);
	else if (height != 64 || width != 64)
		return (mlx_destroy_image(mlx, ptr_img), 1);
	mlx_destroy_image(mlx, ptr_img);
	return (0);
}

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

