/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:44:58 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/14 13:38:55 by npetitpi         ###   ########.fr       */
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
	if (key == XK_Escape)
		exit(7);
	if (key == KEY_W)
		ft_move_player(game, 'W');
	if (key == KEY_S)
		ft_move_player(game, 'S');
	if (key == KEY_A)
		ft_move_player(game, 'A');
	if (key == KEY_D)
		ft_move_player(game, 'D');
	return (key);
}


int	main(void)
{
	t_data	game;

	init_to_null_game(&game);
		
	//CHECK MAP
		
	if (init_mlx(&game))
		return (free_all(&game), 3);
		
	//player_minimap(&game);
// Close window_ptr
	mlx_key_hook(game.window_ptr, ft_key_press, (void *)&game);  //regrouper loophook ?
	mlx_hook(game.window_ptr, 17, 0, ft_press_x, (void *)&game);
	// ...
	// Wait for closing
	mlx_loop(game.mlx_ptr);
	free_all(&game);
	return (0);
}
