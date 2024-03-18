/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <lcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:46:02 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/18 15:49:44 by lcadinot         ###   ########.fr       */
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

int		err_msg(char *s1, char *s2, int ret_val);

/****************************/
/*			FREE			*/
/****************************/

void	destroy_all(t_data *game);
void	ft_free(void *adress);
void	free_tab(char **tab, int n);
void	free_all(t_data *game);

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
void	init_to_null_game(t_data *data);
t_map	*ft_map_init_null(void);
/****************************/
/*			 LIBFT			*/
/****************************/

void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *str);
void	ft_bzero(void *s, size_t n);
char	*ft_strcpy(char *dest, char *src);

/****************************/
/*			 MAP			*/
/****************************/

t_env	*ft_copy_grid(t_env *env, char *buf, int *i);
t_env	*ft_fill_colors(t_env *env, char *buf);
t_env	*ft_fill_texture(t_env *env, char *buf);
int	ft_check_fill(t_env *env, char *buf);
void ft_print_map(t_env *env);
t_map	*ft_fill_grid(t_env *env, const char *av);
void	ft_free_map(t_map *map);

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

int		map_ok(t_data *game, t_env *env, char *file);
int		name_ok(char *file, char *str);
int		check_data_map(char **map);

/****************************/
/*			MAIN			*/
/****************************/

int		ft_key_press(int key, t_data *game);

#endif
