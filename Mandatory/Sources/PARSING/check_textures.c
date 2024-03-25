/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:16:41 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/25 13:22:57 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub.h"

int	to_size(void *mlx, void *ptr_img, char *map)
{
	int	height;
	int	width;

	height = 0;
	width = 0;
	// printf("--------->%p\n", ptr_img);
	ptr_img = mlx_xpm_file_to_image(mlx, map, &height, &width);
	// printf("MLX-------***--------->%p\n", mlx);
	// printf("ptr_img-------***--------->%p\n", ptr_img);
	// printf("MAP-------***--------->%s\n", map);
	// printf("X-------***--------->%d\n", height);
	// printf("Y-------***--------->%d\n", width);
	if (!ptr_img)
		return (1);
	else if (height != 64 || width != 64)
		return (mlx_destroy_image(mlx, ptr_img), 1);
	mlx_destroy_image(mlx, ptr_img);
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

