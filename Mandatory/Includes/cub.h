/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:46:02 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/25 13:28:49 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <limits.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>
# include <stdint.h>

# include "../mlx/mlx.h"
# include "define.h"
# include "struct.h"

/****************************/
/*			 ERROR			*/
/****************************/

int		msg_error(char *s1, char *s2, int ret_val);

/****************************/
/*			FREE			*/
/****************************/

void	destroy_all(t_data *game);
void	destroy_img(t_data *game);
void	ft_free(void *address);
void	free_tab(char **tab, int n);
void	free_all(t_data *game);
void	free_img(t_map map);

/****************************/
/*			 GNL			*/
/****************************/

# define BUFFER_SIZE 10

char	*get_next_line(int fd, int reset);
char	*ft_read_line(int fd, char *line);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *line, char *buff);
char	*ft_line_to_buff(char *line);
char	*ft_read_new_line(char *line);

/****************************/
/*			 INIT			*/
/****************************/

int		check_screen_size(t_data *game);
int		init_mlx(t_data *game);
void	init_to_null_game(t_data *game);
t_map	*ft_map_init_null(void);
/****************************/
/*			 LIBFT			*/
/****************************/

void	*ft_calloc(size_t nmemb, size_t size);
int		ft_strlen(const char *str);
char	*ft_strdup(const char *str);
void	ft_bzero(void *s, size_t n);
char	*ft_strcpy(char *dest, char *src);

/****************************/
/*			 MAP			*/
/****************************/

t_env	*ft_copy_grid(t_env *env, char *buf, int *i);
t_env	*ft_fill_colors(t_env *env, char *buf);
t_env	*ft_fill_texture(t_env *env, char *buf);
int		ft_check_fill(t_env *env, char *buf);
void	ft_print_map(t_env *env);
t_map	*ft_fill_grid(t_env *env, const char *av);
void	ft_free_map_lst(t_map *map);



/****************************/
/*			 MINIMAP		*/
/****************************/

void	player_minimap(t_data *game);

/****************************/
/*			MOVES			*/
/****************************/

void	ft_move_player(t_data *game, char c);


void	ft_move_up(t_data *game);
void	ft_move_down(t_data *game);
void	ft_move_left(t_data *game);
void	ft_move_right(t_data *game);
void	ft_move(int key, t_data *game);

/****************************/
/*			PARSING			*/
/****************************/

int		map_ok(t_data *game,  char *file);
int		name_ok(char *file, char *str);
int		check_data_map(char **map);

/****************************/
/*			MAIN			*/
/****************************/

int		ft_key_press(int key, t_data *game);



/****************************/
/*			TESTuWu			*/
/****************************/

int		render(t_data *game);
void	print_back(t_data *game);
void	raycasting(t_data *game);
void	posi_cam(t_ray *ray, int screen_width, int x);
void	distance_btwn_ray_hv(t_ray *ray);
void	algo_dda(t_ray *ray, t_map *map);
void	wall_lenght(t_ray *ray, int screen_height);
void	draw_wall(t_data *game, int x, t_ray *ray, t_textures *text);
void	print_box(t_data *game, int y, int x, int color);
void	map_to_minimap(t_data *game, int y, int x);
void	move_cam(t_data *game, double mouv);
void	move_player(t_data *d, char c);
void	update_pos(t_data *game, double newpos[2]);
int		init_images(t_data *game);
int		init_textures(t_data *game);
int		visu(t_data *game);
void	init_pos_player(t_data *game);



int		check_open_textures(t_map img);
int		check_wall(char **map);
t_lst	*ft_lstnew(char *str);
t_lst	*ft_lstlast(t_lst *lst);
int		ft_lstsize(t_lst *lst);
int		check_path(t_data *game);
int		map(t_data *game, int fd);
int		verif_game(char **map);
int		is_player(t_data *game, char **map);
int		verif_char(t_lst *check, t_lst *tmp_map);
int		data_map_store(t_data *game, t_lst *stock_map);
t_lst	*mapstore(int fd);
int		path_store(t_data *game, t_lst *maplst, int a);
int		path_store2(t_data *game, t_lst *maplst, int a);
int		path_store3(t_data *game, t_lst *maplst, int a);
int		check_tab(char **tab);
int		check_size_textures(t_map img);
int		algo_rgb(int r, int g, int b);
int		return_is_player(int p);
void	set_value(t_data *game, char c, int i, int j);
void	set_value_2(t_data *game, char c);
int		rgb(t_data *game);
void	player_minimap(t_data *game);


char	*ft_strndup(char *str, int n);

#endif