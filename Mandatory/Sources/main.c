// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: lcadinot <lcadinot@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/03/11 12:44:58 by npetitpi          #+#    #+#             */
// /*   Updated: 2024/03/14 15:32:06 by lcadinot         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "cub.h"

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
	t_env *env;
	(void)ac;

	if (ac != 2)
		return (err_msg(ARG_START, NULL, 1));
	init_to_null_game(&game);
	env = malloc(sizeof(t_env));
	env->map = ft_map_init_null();
	//CHECK MAP A COMPLETER
	if (init_mlx(&game))
		return (free_all(&game), 3);
	if (map_ok(&game, env, av[1])) //test ok -> final : if(check_map(&game, av[1]))
		return (2);
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
// #include <stdio.h>
// #include <math.h>

// #define WIDTH 800
// #define HEIGHT 600
// #define FOV_ANGLE M_PI / 3.0 // Angle de champ de vision (60 degrés)
// #define PLAYER_HEIGHT 32 // Hauteur du joueur
// #define NUM_RAYS WIDTH // Nombre de rayons (colonnes de pixels)

// typedef struct {
//     double x;
//     double y;
// } Vector2D;

// typedef struct {
//     Vector2D start;
//     Vector2D end;
// } Wall;

// typedef struct {
//     Vector2D pos;
//     double angle;
// } Player;

// Player player = {{WIDTH / 2.0, HEIGHT / 2.0}, M_PI / 3.0}; // Position et angle de départ du joueur
// int key_state[280] = {0}; // Tableau pour stocker l'état des touches (appuyée ou non)

// double distance(Vector2D p1, Vector2D p2) {
//     return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
// }

// void movePlayer(double step) {
//     player.pos.x += step * cos(player.angle);
//     player.pos.y += step * sin(player.angle);
// }

// void rotatePlayer(double angle) {
//     player.angle += angle;
//     if (player.angle >= 2 * M_PI) player.angle -= 2 * M_PI;
//     if (player.angle < 0) player.angle += 2 * M_PI;
// }

// void renderScene(void *mlx_ptr, void *win_ptr) {
//     mlx_clear_window(mlx_ptr, win_ptr); // Effacer la fenêtre

//     Wall wall = {{300, 200}, {300, 400}}; // Mur en première personne

//     // Dessiner les murs en perspective
//     for (int i = 0; i < NUM_RAYS; i++) {
//         // Angle du rayon
//         double ray_angle = player.angle + (double)i / NUM_RAYS - FOV_ANGLE / 2.0;

//         // Distance du mur par rapport au joueur
//         double wall_distance = distance(player.pos, wall.start);

//         // Angle du mur par rapport à l'axe x
//         double wall_angle = atan2(wall.end.y - wall.start.y, wall.end.x - wall.start.x);

//         // Différence d'angle entre le joueur et le mur
//         double angle_diff = ray_angle - wall_angle;

//         // Distance perpendiculaire entre le joueur et le mur
//         double perpendicular_distance = wall_distance * cos(angle_diff);

//         // Hauteur du mur à dessiner
//         double wall_height = HEIGHT / perpendicular_distance * PLAYER_HEIGHT;

//         // Position verticale de début et de fin du mur à dessiner
//         double wall_start_y = (HEIGHT - wall_height) / 2.0;
//         double wall_end_y = wall_start_y + wall_height;

//         // Dessiner le mur
//         int color = 0xFFFFFF; // Couleur du mur (blanc)
//         for (int y = wall_start_y; y < wall_end_y; y++) {
//             mlx_pixel_put(mlx_ptr, win_ptr, i, y, color); // Dessiner le mur
//         }
//     }
// }

// int keyPressEvent(int keycode, void *param) {
//     key_state[keycode] = 1;

//     // Déplacement et rotation du joueur en fonction des touches pressées
//     double step = 5.0; // Pas de déplacement
//     double rotate_angle = M_PI / 16.0; // Angle de rotation
//     switch (keycode) {
//         case 119: // Touche W (avancer)
//             movePlayer(step);
//             break;
//         case 115: // Touche S (reculer)
//             movePlayer(-step);
//             break;
//         case 97: // Touche A (tourner à gauche)
//             rotatePlayer(-rotate_angle);
//             break;
//         case 100: // Touche D (tourner à droite)
//             rotatePlayer(rotate_angle);
//             break;
//     }

//     return 0;
// }

// int keyReleaseEvent(int keycode, void *param) {
//     key_state[keycode] = 0;
//     return 0;
// }

// int main() {
//     void *mlx_ptr;
//     void *win_ptr;

//     // Initialisation de la connexion à la fenêtre
//     mlx_ptr = mlx_init();
//     if (!mlx_ptr) {
//         printf("Erreur: Impossible d'initialiser MinilibX.\n");
//         return 1;
//     }

//     // Création de la fenêtre
//     win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "Ray Tracing");

//     // Association des hooks pour la gestion des événements de touche
//     mlx_hook(win_ptr, 2, 0, keyPressEvent, NULL); // KeyPress
//     mlx_hook(win_ptr, 3, 0, keyReleaseEvent, NULL); // KeyRelease

//     // Affichage initial de la scène
//     renderScene(mlx_ptr, win_ptr);

//     // Boucle principale pour maintenir la fenêtre ouverte
//     mlx_loop(mlx_ptr);

//     return 0;
// }


// #include "mlx.h"
// #include <stdio.h>
// #include <math.h>

// #define WIDTH 800
// #define HEIGHT 600
// #define FOV_ANGLE M_PI / 3.0 // Angle de champ de vision (60 degrés)
// #define PLAYER_HEIGHT 32 // Hauteur du joueur
// #define NUM_RAYS WIDTH // Nombre de rayons (colonnes de pixels)

// typedef struct {
//     double x;
//     double y;
// } Vector2D;

// typedef struct {
//     Vector2D start;
//     Vector2D end;
// } Wall;

// typedef struct {
//     Vector2D pos;
//     double angle;
// } Player;

// Player player = {{WIDTH / 2.0, HEIGHT / 2.0}, M_PI / 3.0}; // Position et angle de départ du joueur
// int key_state[280] = {0}; // Tableau pour stocker l'état des touches (appuyée ou non)

// double distance(Vector2D p1, Vector2D p2) {
//     return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
// }

// void movePlayer(double step) {
//     player.pos.x += step * cos(player.angle);
//     player.pos.y += step * sin(player.angle);
// }

// void rotatePlayer(double angle) {
//     player.angle += angle;
//     if (player.angle >= 2 * M_PI) player.angle -= 2 * M_PI;
//     if (player.angle < 0) player.angle += 2 * M_PI;
// }

// void renderScene(void *mlx_ptr, void *win_ptr) {
//     mlx_clear_window(mlx_ptr, win_ptr); // Effacer la fenêtre

//     Wall wall = {{300, 200}, {300, 400}}; // Mur en première personne

//     // Dessiner les murs en perspective
//     for (int i = 0; i < NUM_RAYS; i++) {
//         // Angle du rayon
//         double ray_angle = player.angle + (double)i / NUM_RAYS - FOV_ANGLE / 2.0;

//         // Distance du mur par rapport au joueur
//         double wall_distance = distance(player.pos, wall.start);

//         // Angle du mur par rapport à l'axe x
//         double wall_angle = atan2(wall.end.y - wall.start.y, wall.end.x - wall.start.x);

//         // Différence d'angle entre le joueur et le mur
//         double angle_diff = ray_angle - wall_angle;

//         // Distance perpendiculaire entre le joueur et le mur
//         double perpendicular_distance = wall_distance * cos(angle_diff);

//         // Hauteur du mur à dessiner
//         double wall_height = HEIGHT / perpendicular_distance * PLAYER_HEIGHT;

//         // Position verticale de début et de fin du mur à dessiner
//         double wall_start_y = (HEIGHT - wall_height) / 2.0;
//         double wall_end_y = wall_start_y + wall_height;

//         // Dessiner le mur
//         int color = 0xFFFFFF; // Couleur du mur (blanc)
//         for (int y = wall_start_y; y < wall_end_y; y++) {
//             mlx_pixel_put(mlx_ptr, win_ptr, i, y, color); // Dessiner le mur
//         }
//     }
// }

// int keyPressEvent(int keycode, void *param) {
//     key_state[keycode] = 1;

//     // Déplacement et rotation du joueur en fonction des touches pressées
//     double step = 5.0; // Pas de déplacement
//     double rotate_angle = M_PI / 16.0; // Angle de rotation
//     switch (keycode) {
//         case 119: // Touche W (avancer)
//             movePlayer(step);
//             break;
//         case 115: // Touche S (reculer)
//             movePlayer(-step);
//             break;
//         case 97: // Touche A (tourner à gauche)
//             rotatePlayer(-rotate_angle);
//             break;
//         case 100: // Touche D (tourner à droite)
//             rotatePlayer(rotate_angle);
//             break;
//     }

//     return 0;
// }

// int keyReleaseEvent(int keycode, void *param) {
//     key_state[keycode] = 0;
//     return 0;
// }

// int main() {
//     void *mlx_ptr;
//     void *win_ptr;

//     // Initialisation de la connexion à la fenêtre
//     mlx_ptr = mlx_init();
//     if (!mlx_ptr) {
//         printf("Erreur: Impossible d'initialiser MinilibX.\n");
//         return 1;
//     }

//     // Création de la fenêtre
//     win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "Ray Tracing");

//     // Association des hooks pour la gestion des événements de touche
//     mlx_hook(win_ptr, 2, 0, keyPressEvent, NULL); // KeyPress
//     mlx_hook(win_ptr, 3, 0, keyReleaseEvent, NULL); // KeyRelease

//     // Affichage initial de la scène
//     renderScene(mlx_ptr, win_ptr);

//     // Boucle principale pour maintenir la fenêtre ouverte
//     mlx_loop(mlx_ptr);

//     return 0;
// }





/////////////////////////////////////////////////////////////////////////RAYCASTING_MAIN


// #define MAP_WIDTH 24
// #define MAP_HEIGHT 24

// int worldMap[MAP_WIDTH][MAP_HEIGHT] =
// {
//     {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
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
//     int dx = abs(x1 - x0);
//     int dy = abs(y1 - y0);
//     int sx = x0 < x1 ? 1 : -1;
//     int sy = y0 < y1 ? 1 : -1;
//     int err = (dx > dy ? dx : -dy) / 2;
//     int err_temp;

//     while (1) 
//     {
//         mlx_pixel_put(mlx_ptr, Window_ptr, x0, y0, color);
//         if (x0 == x1 && y0 == y1) 
//             break;
//         err_temp = err;
//         if (err_temp > -dx) { err -= dy; x0 += sx; }
//         if (err_temp < dy) { err += dx; y0 += sy; }
//     }
// }

// void cast_rays(void *mlx_ptr, void *Window_ptr)
// {
//     for (int x = 0; x < Window_WIDTH; x++) 
//     {
//         float rayAngle = (playerA - FOV / 2) + ((float)x / Window_WIDTH) * FOV;

//         float Distance_Murs = 0;
//         float Line_Horizontale = sin(rayAngle);
//         float Line_Verticale = cos(rayAngle);

//         while (1) 
//         {
//             Distance_Murs += 0.1f;

//             int testX = (int)(playerX + Line_Horizontale * Distance_Murs);
//             int testY = (int)(playerY + Line_Verticale * Distance_Murs);

//             if (testX < 0 || testX >= MAP_WIDTH || testY < 0 || testY >= MAP_HEIGHT)
//             {
//                 Distance_Murs = 100;
//                 break;
//             } else if (worldMap[testX][testY] == 1)
//             {
//                 break;
//             }
//         }

//         float Plafond = (float)(Window_HEIGHT / 2.0) - Window_HEIGHT / ((float)Distance_Murs);
//         float Sol = Window_HEIGHT - Plafond;

//         // Draw Murss
//         draw_line(mlx_ptr, Window_ptr, x, 0, x, Plafond, 0xFFFFFF); // Plafond
//         draw_line(mlx_ptr, Window_ptr, x, Plafond, x, Sol, 0xAAAAAA); // Murs
//         draw_line(mlx_ptr, Window_ptr, x, Sol, x, Window_HEIGHT, 0x444444); // Sol
//     }
// }
