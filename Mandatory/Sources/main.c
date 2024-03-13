/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:44:58 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/13 14:34:31 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// int main(int ac, char **av)
// {
// 	t_env *env;

// 	(void)ac;
// 	env = (t_env *)malloc(sizeof(t_env));
// 	env->map = ft_map_init();
// 	env->map = ft_fill_grid(env, av[1]);
// 	ft_free_map(env->map);
// 	free(env);
// 	return (0);
// }

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
	else
		ft_move(key, game);
	return (0);
}

int	main(void)
{
	t_data	game;

	init_to_null_game(&game);
	if (init_mlx(&game))
		return (free_all(&game), 3);
	//player_minimap(&game); //
	// Close window_ptr
	mlx_key_hook(game.window_ptr, ft_key_press, (void *)&game);
	mlx_hook(game.window_ptr, 17, 0, ft_press_x, (void *)&game);
	// ...
	// Wait for closing
	mlx_loop(game.mlx_ptr);
}
