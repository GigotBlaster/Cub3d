/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:44:58 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/18 13:53:37 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// int main(int ac, char **av)
// {
// 	t_env *env;

// 	(void)ac;
// 	env = (t_env *)malloc(sizeof(t_env));
// 	env->map = ft_map_init_null();
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


int	main(int ac, char **av)
{
	t_data	game;
	(void)ac;

	if (ac != 2)
		return (err_msg(ARG_START, NULL, 1));
	init_to_null_game(&game);
		
	//CHECK MAP A COMPLETER
	if (map_ok(&game, av[1])) //test ok -> final : if(check_map(&game, av[1]))
		return (2);
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





/////////////////////////////////////////////////////////////////////////RAYCASTING_MAIN

// #define MAP_WIDTH 24
// #define MAP_HEIGHT 24

// int worldMap[MAP_WIDTH][MAP_HEIGHT] =
// {
// 	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
// 	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
// };

// #define Window_WIDTH 800
// #define Window_HEIGHT 600
// #define FOV (M_PI / 3)  // lib math.h //champ de vision 60degre en radians. = pi /3

// float playerX = 12.0f;  //placement dans la carte coordonee x
// float playerY = 12.0f; //placement dans la carte coordonee y
// float playerA = 0.0f;  //orienté vers la droite de la carte

// // algorithme de Bresenham pour dessiner une ligne entre deux points
// void draw_line(void *mlx_ptr, void *Window_ptr, int x0, int y0, int x1, int y1, int color)
// {
// 	int dx = abs(x1 - x0);
// 	int dy = abs(y1 - y0);
// 	int sx = x0 < x1 ? 1 : -1;
// 	int sy = y0 < y1 ? 1 : -1;
// 	int err = (dx > dy ? dx : -dy) / 2;
// 	int err_temp;

// 	while (1) 
// 	{
// 		mlx_pixel_put(mlx_ptr, Window_ptr, x0, y0, color);
// 		if (x0 == x1 && y0 == y1) 
// 			break;
// 		err_temp = err;
// 		if (err_temp > -dx) { err -= dy; x0 += sx; }
// 		if (err_temp < dy) { err += dx; y0 += sy; }
// 	}
// }

// void cast_rays(void *mlx_ptr, void *Window_ptr)
// {
// 	for (int x = 0; x < Window_WIDTH; x++) 
// 	{
// 		float rayAngle = (playerA - FOV / 2) + ((float)x / Window_WIDTH) * FOV;

// 		float Distance_Murs = 0;
// 		float Line_Horizontale = sin(rayAngle);
// 		float Line_Verticale = cos(rayAngle);

// 		while (1) 
// 		{
// 			Distance_Murs += 0.1f;

// 			int testX = (int)(playerX + Line_Horizontale * Distance_Murs);
// 			int testY = (int)(playerY + Line_Verticale * Distance_Murs);

// 			if (testX < 0 || testX >= MAP_WIDTH || testY < 0 || testY >= MAP_HEIGHT)
// 			{
// 				Distance_Murs = 100;
// 				break;
// 			} else if (worldMap[testX][testY] == 1)
// 			{
// 				break;
// 			}
// 		}

// 		float Plafond = (float)(Window_HEIGHT / 2.0) - Window_HEIGHT / ((float)Distance_Murs);
// 		float Sol = Window_HEIGHT - Plafond;

// 		// Draw Murss
// 		draw_line(mlx_ptr, Window_ptr, x, 0, x, Plafond, 0xFFFFFF); // Plafond
// 		draw_line(mlx_ptr, Window_ptr, x, Plafond, x, Sol, 0xAAAAAA); // Murs
// 		draw_line(mlx_ptr, Window_ptr, x, Sol, x, Window_HEIGHT, 0x444444); // Sol
// 	}
// }

// void cast_rays(void *mlx_ptr, void *Window_ptr)
// {
// 	for (int x = 0; x < Window_WIDTH; x++) 
// 	{
// 		float rayAngle = (playerA - FOV / 2) + ((float)x / Window_WIDTH) * FOV;

// 		float Distance_Murs = 0;
// 		float Line_Horizontale = sin(rayAngle);
// 		float Line_Verticale = cos(rayAngle);

// 		while (1) 
// 		{
// 			Distance_Murs += 0.1f;

// 			int testX = (int)(playerX + Line_Horizontale * Distance_Murs);
// 			int testY = (int)(playerY + Line_Verticale * Distance_Murs);

// 			if (testX < 0 || testX >= MAP_WIDTH || testY < 0 || testY >= MAP_HEIGHT)
// 			{
// 				Distance_Murs = 100;
// 				break;
// 			} else if (worldMap[testX][testY] == 1)
// 			{
// 				break;
// 			}
// 		}

// 		float Plafond = (float)(Window_HEIGHT / 2.0) - Window_HEIGHT / ((float)Distance_Murs);
// 		float Sol = Window_HEIGHT - Plafond;

// 		// Draw Murss
// 		draw_line(mlx_ptr, Window_ptr, x, 0, x, Plafond, 0xFFFFFF); // Plafond
// 		draw_line(mlx_ptr, Window_ptr, x, Plafond, x, Sol, 0xAAAAAA); // Murs
// 		draw_line(mlx_ptr, Window_ptr, x, Sol, x, Window_HEIGHT, 0x444444); // Sol
// 	}
// }

// int main()
// {
// 	void *mlx_ptr;
// 	void *Window_ptr;

// 	mlx_ptr = mlx_init();
// 	Window_ptr = mlx_new_window(mlx_ptr, Window_WIDTH, Window_HEIGHT, "My Wolfenstein");

// 	cast_rays(mlx_ptr, Window_ptr);

// 	mlx_loop(mlx_ptr);
// 	return(0);
// }

