/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testuwu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <lcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:18:36 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/26 14:37:44 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*ft_strtrim(char *str, char c)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	while (str[i] == c)
		i++;
	j = ft_strlen(str) - 1;
	if (j <= 0)
		return (ft_free(str), NULL);
	while (str[j] == c)
		j--;
	if (i > j)
		return (ft_free(str), NULL);
	res = ft_strndup(str + i, j - i + 1);
	if (!res)
		return (ft_free(str), NULL);
	ft_free(str);
	return (res);
}

char	*ft_strndup(char *str, int n)
{
	int		i;
	char	*dup;

	i = -1;
	if (!str)
		return (NULL);
	dup = ft_calloc(ft_strlen(str) + 1, 1);
	if (!dup)
		return (NULL);
	if (n == 0)
	{
		while (str[++i])
			dup[i] = str[i];
	}
	else
	{
		while (++i < n && str[i])
			dup[i] = str[i];
	}
	return (dup);
}

int	ft_strncmp(char *str, char *to_find, int n)
{
	int	i;

	i = 0;
	if (!str || !to_find)
		return (0);
	while (str[i] && to_find[i] && str[i] == to_find[i] && i < n)
		i++;
	if (i == n)
		return (1);
	return (0);
}

int	ft_strchr2(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (1);
	return (0);
}


int	word_count(char *str, char set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && str[i] == set)
			i++;
		while (str[i] && str[i] != set)
		{
			if (str[i + 1] == set || str[i + 1] == '\0')
				j++;
			i++;
		}
	}
	return (j);
}

int	char_count(char *str, char set, int pos)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		while (str[i] && str[i] == set)
			i++;
		while (str[i] && str[i] != set)
		{
			if (j == pos)
				k++;
			if (str[i + 1] == set || str[i + 1] == '\0')
				j++;
			i++;
		}
	}
	return (k);
}

char	*ft_putword(char *str, char *tab, char set, int pos)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		while (str[i] && str[i] == set)
			i++;
		while (str[i] && str[i] != set)
		{
			if (j == pos)
			{
				tab[k] = str[i];
				k++;
			}
			if (str[i + 1] == set || str[i + 1] == '\0')
				j++;
			i++;
		}
	}
	tab[k] = '\0';
	return (tab);
}

char	**ft_split(char	*str, char set)
{
	int		j;
	char	**tab;

	j = 0;
	if (!str)
		return (NULL);
	tab = ft_calloc(sizeof(char *), word_count(str, set) + 1);
	if (!tab)
		return (ft_free(tab), NULL);
	while (j < word_count(str, set))
	{
		tab[j] = ft_calloc(1, char_count(str, set, j) + 1);
		if (!tab[j])
			return (free_tab(tab, 0), NULL);
		tab[j] = ft_putword(str, tab[j], set, j);
		j++;
	}
	tab[j] = 0;
	return (tab);
}

long	ft_atoi(char *str)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * sign);
}

int	is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i])
		return (1);
	return (0);
}

/////////////////////////////////////////////////////UTILS


int	init_images(t_data *game)
{
	game->img[NORTH].img = mlx_xpm_file_to_image(game->mlx_ptr,
			game->map.n_texture_path, &game->img[NORTH].width,
			&game->img[NORTH].height);
	if (!game->img[NORTH].img)
		return (msg_error(game->map.n_texture_path, XPM, 1));
	game->img[SOUTH].img = mlx_xpm_file_to_image(game->mlx_ptr,
			game->map.s_texture_path, &game->img[SOUTH].width,
			&game->img[SOUTH].height);
	if (!game->img[SOUTH].img)
		return (msg_error(game->map.s_texture_path, XPM, 2));
	game->img[EAST].img = mlx_xpm_file_to_image(game->mlx_ptr,
			game->map.e_texture_path, &game->img[EAST].width,
			&game->img[EAST].height);
	if (!game->img[EAST].img)
		return (msg_error(game->map.e_texture_path, XPM, 3));
	game->img[WEST].img = mlx_xpm_file_to_image(game->mlx_ptr,
			game->map.w_texture_path, &game->img[WEST].width,
			&game->img[WEST].height);
	if (!game->img[WEST].img)
		return (msg_error(game->map.w_texture_path, XPM, 4));
	return (0);
}


/////////////////////////////////////////////////////////////////////////////////////////

int	render(t_data *game)
{
	int	x;
	int	y;

	x = 0;
	print_back(game);
	raycasting(game);
	while (game->map.grid[x])
	{
		y = 0;
		while (game->map.grid[x][y])
		{
			map_to_minimap(game, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(game-> mlx_ptr, game->window_ptr, game->img[VISU].img, 0, 0);
	return (0);
}


void	print_back(t_data *game)
{
	int	j;
	int	i;

	j = 0;
	while (j < SCREEN_HEIGHT / 2)
	{
		i = -1;
		while (++i < SCREEN_WIDTH)
			game->img[VISU].address[j * game->img[VISU].line_lengh_pix / 4 + i]
				= game->map.c_color_int;
		j++;
	}
		//printf("%d\n", game->img[VISU].address[j * game->img[VISU].line_lengh_pix / 4 + i]);
	while (j < SCREEN_HEIGHT)
	{
		i = -1;
		while (++i < SCREEN_WIDTH)
			game->img[VISU].address[j * game->img[VISU].line_lengh_pix / 4 + i]
				= game->map.f_color_int;
		j++;
	}
}


void	init_walls(t_ray *ray, t_textures *text)
{
	if (ray->side == 0 && ray->raydir[X] < 0)
		text->dir_text = 0;
	if (ray->side == 0 && ray->raydir[X] > 0)
		text->dir_text = 1;
	if (ray->side == 1 && ray->raydir[Y] < 0)
		text->dir_text = 2;
	if (ray->side == 1 && ray->raydir[Y] > 0)
		text->dir_text = 3;
	if (ray->side == 0)
		text->wall_x = ray->pos[Y] + ray->texture_dist * ray->raydir[Y];
	else
		text->wall_x = ray->pos[X] + ray->texture_dist * ray->raydir[X];
	text->wall_x -= floor(text->wall_x);
}


/////////////////////////////////////////////////////////////RAYCAST

void	raycasting(t_data *game)
{
	int	x;

	print_back(game);
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		posi_cam(&game->ray, SCREEN_WIDTH, x);
		distance_btwn_ray_hv(&game->ray);
		algo_dda(&game->ray, &game->map);
		wall_lenght(&game->ray, SCREEN_HEIGHT);
		draw_wall(game, x, &game->ray, &game->textures);
		x++;
	}
}

void	posi_cam(t_ray *ray, int screen_width, int x)
{
	ray->cam_x = 2.0 * x / (double)screen_width - 1;
	ray->raydir[X] = ray->dir[X] + ray->plan[X] * ray->cam_x;
	ray->raydir[Y] = ray->dir[Y] + ray->plan[Y] * ray->cam_x;
	ray->map[X] = (int)ray->pos[X];
	ray->map[Y] = (int)ray->pos[Y];
	ray->delta[X] = fabs(1 / ray->raydir[X]);
	ray->delta[Y] = fabs(1 / ray->raydir[Y]);
}

void	wall_lenght(t_ray *ray, int screen_height)
{
	if (ray->side == 0)
		ray->texture_dist = (ray->ray_side[X] - ray->delta[X]);
	else
		ray->texture_dist = (ray->ray_side[Y] - ray->delta[Y]);
	if (ray->texture_dist == 0)
		ray->texture_dist = 0.01;
	ray->height_l = (double)(screen_height / ray->texture_dist);
	ray->draw_start = (screen_height / 2) - (ray->height_l / 2);
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = (screen_height / 2) + (ray->height_l / 2);
	if (ray->draw_end >= screen_height)
		ray->draw_end = screen_height;
}

void	distance_btwn_ray_hv(t_ray *ray)
{
	if (ray->raydir[X] < 0)
		ray->ray_side[X] = (ray->pos[X] - ray->map[X]) * ray->delta[X];
	else
		ray->ray_side[X] = (ray->map[X] + 1.0 - ray->pos[X])
			* ray->delta[X];
	if (ray->raydir[Y] < 0)
		ray->ray_side[Y] = (ray->pos[Y] - ray->map[Y]) * ray->delta[Y];
	else
		ray->ray_side[Y] = (ray->map[Y] + 1.0 - ray->pos[Y])
			* ray->delta[Y];
	if (ray->raydir[X] < 0)
		ray->step[X] = -1;
	else
		ray->step[X] = 1;
	if (ray->raydir[Y] < 0)
		ray->step[Y] = -1;
	else
		ray->step[Y] = 1;
}


void	algo_dda(t_ray *ray, t_map *map)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		if (ray->ray_side[X] < ray->ray_side[Y])
		{
			ray->ray_side[X] += ray->delta[X];
			ray->map[X] += ray->step[X];
			ray->side = 0 ;
		}
		else
		{
			ray->ray_side[Y] += ray->delta[Y];
			ray->map[Y] += ray->step[Y];
			ray->side = 1 ;
		}
		if (map->grid[ray->map[Y]][ray->map[X]] == '1')
			ray->hit = 1;
	}
}

void	draw_wall(t_data *game, int x, t_ray *ray, t_textures *text)
{
	int	j;

	init_walls(ray, text);
	j = ray->draw_start;
	text->tex_x = (int)(text->wall_x * (float)game->img[text->dir_text].width);
	if (ray->side == 0 && ray->raydir[X] > 0)
		text->tex_x = game->img[text->dir_text].width - text->tex_x - 1;
	if (ray->side == 1 && ray->raydir[Y] < 0)
		text->tex_x = game->img[text->dir_text].width - text->tex_x - 1;
	text->step = 1.0 * game->img[text->dir_text].height / ray->height_l;
	text->tex_pos = (ray->draw_start - SCREEN_HEIGHT / 2 + \
		ray->height_l / 2) * text->step;
	while (j <= ray->draw_end)
	{
		text->tex_y = (int)text->tex_pos & (game->img[text->dir_text].height - 1);
		text->tex_pos += text->step;
		if (j < SCREEN_HEIGHT && x < SCREEN_WIDTH)
			game->img[VISU].address[j * game->img[VISU].line_lengh_pix / 4 + x]
				= game->img[text->dir_text].address[text->tex_y
				* game->img[text->dir_text].line_lengh_pix / 4 + text->tex_x];
		j++;
	}
}

////////////////////////////////////////////////////////////////LIST princess


t_lst	*ft_lstnew(char *str)
{
	t_lst	*node;

	node = ft_calloc(1, sizeof(t_lst));
	if (!node)
		return (NULL);
	node->mapline = str;
	node->next = NULL;
	return (node);
}

t_lst	*ft_lstlast(t_lst *lst)
{
	t_lst	*last;

	last = lst;
	if (!lst)
		return (NULL);
	while (last->next)
		last = last->next;
	return (last);
}

int	ft_lstsize(t_lst *lst)
{
	t_lst	*last;
	int		i;

	i = 0;
	last = lst;
	if (!lst)
		return (0);
	while (last)
	{
		last = last->next;
		i++;
	}
	return (i);
}

void	free_lstmap(t_lst *lst_map)
{
	t_lst	*before;

	if (!lst_map)
		return ;
	before = lst_map;
	while (lst_map)
	{
		lst_map = lst_map->next;
		ft_free(before->mapline);
		ft_free(before);
		before = lst_map;
	}
}

int	check_path(t_data *game)
{
	if (game->map.n_texture_path == NULL)
		return (1);
	else if (game->map.s_texture_path == NULL)
		return (1);
	else if (game->map.w_texture_path == NULL)
		return (1);
	else if (game->map.e_texture_path == NULL)
		return (1);
	else if (game->map.f_color == NULL)
		return (1);
	else if (game->map.c_color == NULL)
		return (1);
	return (0);
}

int	map(t_data *game, int fd)
{
	t_lst	*ltmap;
	t_lst	*tmp_map;
	int		a;

	ltmap = mapstore(fd);

	if (!ltmap)
		return (1);
	tmp_map = ltmap;
	while (tmp_map)
	{
		a = ft_strlen(tmp_map->mapline);
		if (path_store(game, tmp_map, a))
			break ;
		tmp_map = tmp_map->next;
	}
	if (check_path(game))
		return (free_all(game), free_lstmap(ltmap), msg_error(INV_MAP, NULL, 2));
	if (data_map_store(game, tmp_map) || is_player(game, game->map.grid)
		|| verif_game(game->map.grid))
		return (free_all(game), free_lstmap(ltmap),
			msg_error(INV_MAP, NULL, 1), 3);
	free_lstmap(ltmap);
	return (0);
}

int	verif_game(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != '1' && map[i][j] != '0'
				&& map[i][j] != ' ')
				return (1);
		}
	}
	return (0);
}




int	return_is_player(int player)
{
	if (player < 1)
		return (msg_error(NO_PLAYER, NULL, 1));
	else if (player > 1)
		return (msg_error(TOO_PLAYER, NULL, 1));
	return (0);
}

int	verif_char(t_lst *check, t_lst *tmp_map)
{
	int	i;

	while (tmp_map->mapline[0] == '\n')
		tmp_map = tmp_map->next;
	while (check)
	{
		i = 0;
		while (check->mapline[i])
		{
			if (check->mapline[i] == ' ' || check->mapline[i] == '0'
				|| check->mapline[i] == '1' || check->mapline[i] == '\n')
				i++;
			else if (check->mapline[i] == 'N' || check->mapline[i] == 'S'
				|| check->mapline[i] == 'E' || check->mapline[i] == 'W')
				i++;
			else
				return (1);
		}
		check = check->next;
	}
	return (0);
}


int	data_map_store(t_data *game, t_lst *stock_map)
{
	int	i;
	t_lst *check;

	check = stock_map;
	if (verif_char(check, stock_map))
		return (1);
	game->map.height = ft_lstsize(stock_map);
	game->map.grid = ft_calloc(game->map.height + 1, sizeof(char *));
	game->map.grid[game->map.height] = NULL;
	if (!game->map.grid)
		return (1);
	i = -1;
	while (stock_map)
	{
		if (stock_map->mapline[ft_strlen(stock_map->mapline) - 1] == '\n')
			stock_map->mapline[ft_strlen(stock_map->mapline) - 1] = '\0';
		game->map.grid[++i] = ft_strndup(stock_map->mapline,
				(ft_strlen(stock_map->mapline)));
		if (game->map.width < (ft_strlen(stock_map->mapline)))
			game->map.width = (ft_strlen(stock_map->mapline));
		if (!game->map.grid[i])
			return (1);
		stock_map = stock_map->next;
	}
	return (0);
}



t_lst	*mapstore(int fd)
{
	t_lst	*map_lst;
	t_lst	*tmp;
	char	*line;

	line = get_next_line(fd, 0);
	if (!line)
		return (msg_error(MALLOC, NULL, 1), NULL);
	tmp = ft_lstnew(line);
	map_lst = tmp;
	if (!tmp)
		return (msg_error(MALLOC, NULL, 2), NULL);
	while (line)
	{
		line = get_next_line(fd, 0);
		if (!line)
			break ;
		ft_lstlast(tmp)->next = ft_lstnew(line);
	}
	return (map_lst);
}

int	path_store(t_data *game, t_lst *ltmap, int a)
{
	if (!ltmap || !ltmap->mapline)
		return (1);
	//printf("--------***------>%s\n", ltmap->mapline); good
	if (ft_strncmp(ltmap->mapline, "NO ", 3))
	{
		if (game->map.n_texture_path)
			return (2);
		game->map.n_texture_path = ft_strndup((ltmap->mapline + 3), (a - 4));
		game->map.n_texture_path = ft_strtrim(game->map.n_texture_path, ' ');
		//printf("--------***------>%s\n", game->map.n_texture_path);
	}
	else if (ft_strncmp(ltmap->mapline, "SO ", 3))
	{
		if (game->map.s_texture_path)
			return (2);
		game->map.s_texture_path = ft_strndup(ltmap->mapline + 3, (a - 4));
		game->map.s_texture_path = ft_strtrim(game->map.s_texture_path, ' ');
	}
	else
		return (path_store2(game, ltmap, a));
	return (0);
}

int	path_store2(t_data *game, t_lst *ltmap, int a)
{
	if (ft_strncmp(ltmap->mapline, "WE ", 3))
	{
		if (game->map.w_texture_path)
			return (2);
		game->map.w_texture_path = ft_strndup(ltmap->mapline + 3, (a - 4));
		game->map.w_texture_path = ft_strtrim(game->map.w_texture_path, ' ');
	}
	else if (ft_strncmp(ltmap->mapline, "EA ", 3))
	{
		if (game->map.e_texture_path)
			return (2);
		game->map.e_texture_path = ft_strndup(ltmap->mapline + 3, (a - 4));
		game->map.e_texture_path = ft_strtrim(game->map.e_texture_path, ' ');
	}
	else if (ft_strncmp(ltmap->mapline, "F ", 2))
	{
		if (game->map.f_color)
			return (2);
		game->map.f_color = ft_strndup(ltmap->mapline + 2, (a - 3));
		game->map.f_color = ft_strtrim(game->map.f_color, ' ');
	}
	else
		return (path_store3(game, ltmap, a));
	return (0);
}

int	path_store3(t_data *game, t_lst *ltmap, int a)
{
	if (ft_strncmp(ltmap->mapline, "C ", 2))
	{
		if (game->map.c_color)
			return (2);
		game->map.c_color = ft_strndup(ltmap->mapline + 2, (a - 3));
		game->map.c_color = ft_strtrim(game->map.c_color, ' ');
	}
	else if (ltmap->mapline[0] != '\n')
		return (3);
	return (0);
}



int	check_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
	{
		if (is_digit(tab[i]))
			return (1);
		if (ft_atoi(tab[i]) < 0 || ft_atoi(tab[i]) > 255)
			return (1);
		if (ft_strlen(tab[i]) > 3)
			return (1);
		if (i > 3)
			return (1);
	}
	return (0);
}
//princess
int	algo_rgb(int r, int g, int b)
{
	return (r * 12500 + g * 256 + b);
}


void	set_value(t_data *game, char c, int i, int j)
{
	if (c == 'N')
	{
		game->ray.dir[X] = 0;
		game->ray.dir[Y] = -1;
		game->ray.plan[X] = 0.66;
		game->ray.plan[Y] = 0;
		game->player[ANGLE] = M_PI / 2;
	}
	else if (c == 'S')
	{
		game->ray.dir[X] = 0;
		game->ray.dir[Y] = 1;
		game->ray.plan[X] = -0.66;
		game->ray.plan[Y] = 0;
		game->player[ANGLE] = 1.5 * M_PI;
	}
	else
		set_value_2(game, c);
	game->player[POS_Y] = i;
	game->player[POS_X] = j;
}

void	set_value_2(t_data *game, char c)
{
	if (c == 'E')
	{
		game->ray.dir[X] = 1;
		game->ray.dir[Y] = 0;
		game->ray.plan[X] = 0;
		game->ray.plan[Y] = 0.66;
		game->player[ANGLE] = M_PI;
	}
	else if (c == 'W')
	{
		game->ray.dir[X] = -1;
		game->ray.dir[Y] = 0;
		game->ray.plan[X] = 0;
		game->ray.plan[Y] = -0.66;
		game->player[ANGLE] = 0;
	}
}

int	is_player(t_data *game, char **map)
{
	int	i;
	int	j;
	int	p;

	i = -1;
	p = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E')
			{
				p++;
				set_value(game, map[i][j], i, j);
				game->map.grid[i][j] = '0';
			}
		}
	}
	return (return_is_player(p));
}

//princess 
int	rgb(t_data *game)
{
	char	**tab;
	int		tab_int[3];

	tab = ft_split(game->map.c_color, ',');
	if (check_tab(tab))
		return (free_tab(tab, 0), 1);
	tab_int[0] = ft_atoi(tab[0]);
	tab_int[1] = ft_atoi(tab[1]);
	tab_int[2] = ft_atoi(tab[2]);
	game->map.c_color_int = algo_rgb(tab_int[0], tab_int[1], tab_int[2]);
	free_tab(tab, 0);
	tab = ft_split(game->map.f_color, ',');
	if (check_tab(tab))
		return (free_tab(tab, 0), 1);
	tab_int[0] = ft_atoi(tab[0]);
	tab_int[1] = ft_atoi(tab[1]);
	tab_int[2] = ft_atoi(tab[2]);
	game->map.f_color_int = algo_rgb(tab_int[0], tab_int[1], tab_int[2]);
	free_tab(tab, 0);
	return (0);
}
