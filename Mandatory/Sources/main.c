/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:44:58 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/28 11:56:30 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// void move_forward(t_data *game, double speed) {
//     // Vérifier si la nouvelle position en X est accessible (pas de mur)
//     if (game->map.grid[(int)(game->ray.pos[Y])]
//                       [(int)(game->ray.pos[X] + game->ray.dir[X] * speed)] == '0') {
//         game->ray.pos[X] += game->ray.dir[X] * speed;
//     }
//     // Vérifier si la nouvelle position en Y est accessible (pas de mur)
//     if (game->map.grid[(int)(game->ray.pos[Y] + game->ray.dir[Y] * speed)]
//                       [(int)(game->ray.pos[X])] == '0') {
//         game->ray.pos[Y] += game->ray.dir[Y] * speed;
//     }
// }

// void move_left(t_data *game, double speed) {
//     if (game->map.grid[(int)(game->ray.pos[Y])]
//                       [(int)(game->ray.pos[X] - game->ray.plan[X] * speed)] == '0') {
//         game->ray.pos[X] -= game->ray.plan[X] * speed;
//     }
//     if (game->map.grid[(int)(game->ray.pos[Y] - game->ray.plan[Y] * speed)]
//                       [(int)(game->ray.pos[X])] == '0') {
//         game->ray.pos[Y] -= game->ray.plan[Y] * speed;
//     }
// }

// void move_right(t_data *game, double speed) {
//     if (game->map.grid[(int)(game->ray.pos[Y])]
//                       [(int)(game->ray.pos[X] + game->ray.plan[X] * speed)] == '0') {
//         game->ray.pos[X] += game->ray.plan[X] * speed;
//     }
//     if (game->map.grid[(int)(game->ray.pos[Y] + game->ray.plan[Y] * speed)]
//                       [(int)(game->ray.pos[X])] == '0') {
//         game->ray.pos[Y] += game->ray.plan[Y] * speed;
//     }
// }


// void move_backward(t_data *game, double speed) {
//     if (game->map.grid[(int)(game->ray.pos[Y])]
//                       [(int)(game->ray.pos[X] - game->ray.dir[X] * speed)] == '0') {
//         game->ray.pos[X] -= game->ray.dir[X] * speed;
//     }
//     if (game->map.grid[(int)(game->ray.pos[Y] - game->ray.dir[Y] * speed)]
//                       [(int)(game->ray.pos[X])] == '0') {
//         game->ray.pos[Y] -= game->ray.dir[Y] * speed;
//     }
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
	if (key == KEY_LEFT)
		move_cam(game, -0.1);
	if (key == KEY_W)
		motion(game, 'W');
	if (key == KEY_A)
		motion(game, 'A');
	if (key == KEY_S)
		motion(game, 'S');
	if (key == KEY_D)
		motion(game, 'D');
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
	mlx_hook(game.window_ptr, MotionNotify, PointerMotionMask,
		&cam_mouse, &game);
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

