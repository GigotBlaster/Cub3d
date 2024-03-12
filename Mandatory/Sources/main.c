/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:44:58 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/12 12:58:24 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_press_x(t_data *game)
{
	ft_key_press(KEY_ESC, game);
	return (0);
}

int	ft_key_press(int key, t_data *game)
{
	if (key == KEY_ESC)
	{
	//	ft_clear_images(game);
	//	ft_free_map(game);
		mlx_destroy_window(game->mlx_ptr, game->window_ptr);
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
		exit(EXIT_FAILURE);
	}
	// else
	// 	ft_move(key, game);
	return (0);
}

int	main(void)
{
	t_data	game;

	// Init connexion mlx
	game.mlx_ptr = mlx_init();
	if (game.mlx_ptr == NULL)
	{
		write(2, "Error\nMissing graphical interface.\n", 35);
	//	ft_free_map(&game);
		return (4);
	}
	// Créer fenêtre
	game.window_ptr = mlx_new_window(game.mlx_ptr, 1024, 512, "My Wolfenstein");
	if (game.window_ptr == NULL)
		return (4);
	// Close window_ptr
	mlx_key_hook(game.window_ptr, ft_key_press, (void *)&game);
	mlx_hook(game.window_ptr, 17, 0, ft_press_x, (void *)&game);
	// ...
	// Wait for closing
	mlx_loop(game.mlx_ptr);
}

