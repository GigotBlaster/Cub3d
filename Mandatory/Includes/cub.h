/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <lcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:46:02 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/12 14:17:15 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <math.h>
# include <fcntl.h>
# include <stdint.h>
# include "../mlx/mlx.h"
# include "define.h"
# include "struct.h"

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

//libft

void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *str);
void	ft_bzero(void *s, size_t n);

//map

void ft_free_map(t_map *map);
t_map *ft_map_init(void);
t_map *ft_fill_grid(t_env *env, const char *av);
/****************************/
/*			MOVES			*/
/****************************/

void	ft_move_up(t_data *game);

void	ft_move(int key, t_data *game);

/****************************/
/*			MAIN			*/
/****************************/

int	ft_key_press(int key, t_data *game);

#endif
