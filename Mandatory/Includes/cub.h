/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <lcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:46:02 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/12 14:04:58 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <math.h>
# include <fcntl.h>
# include <stdint.h>

# include "struct.h"

# define KEY_ESC		65307
# define KEY_UP			65362
# define KEY_DOWN		65364
# define KEY_LEFT		65361
# define KEY_RIGHT		65363
# define KEY_A			97
# define KEY_W			119
# define KEY_S			115
# define KEY_D			100

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
