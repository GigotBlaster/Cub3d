/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:44:58 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/26 13:39:06 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// int	ft_key_press(int key, t_data *game)
// {
// 	if (key == XK_Escape)
// 		exit(7);
// 	if (key == KEY_W)
// 		ft_move_player(game, 'W');
// 	if (key == KEY_S)
// 		ft_move_player(game, 'S');
// 	if (key == KEY_A)
// 		ft_move_player(game, 'A');
// 	if (key == KEY_D)
// 		ft_move_player(game, 'D');
// 	return (key);
// }

int	keypress(int key, t_data *game)
{
	if (key == XK_Escape)
	{
		free_all(game);
		exit (7);
	}
	if (key == KEY_RIGHT)
		move_cam(game, 0.1);
	if	(key == KEY_LEFT)
		move_cam(game, -0.1);
	return (key);
}

int	key_realease(t_data *game)
{
	free_all(game);
	exit (8);
	return (0);
}


void	loop_hook(t_data game)
{
	mlx_loop_hook(game.mlx_ptr, &render, &game);
	mlx_hook(game.window_ptr, KeyPress, KeyPressMask, &keypress, &game);
	mlx_hook(game.window_ptr, ClientMessage, LeaveWindowMask, &key_realease,
		&game);
	mlx_loop(game.mlx_ptr);
}


int	main(int ac, char **av)
{
	t_data	game;
//	t_env *env;
	(void)ac;

	game = (t_data){0}; //princess
	if (ac != 2)
		return (msg_error(ARG_START, NULL, 1));
	init_to_null_game(&game);
//	env = malloc(sizeof(t_env));
	//env->map = ft_map_init_null();
		
	//CHECK MAP A COMPLETER
	if (map_ok(&game, av[1]))
		return (2);
	if (init_mlx(&game))
		return (free_all(&game), 3);
		
// 	//player_minimap(&game);
// // Close window_ptr
	loop_hook(game);
// 	// ...
// 	// Wait for closing
// 	//ft_free_map(env->map);
// //	free(env);
 	free_all(&game);
	return (0);
}

