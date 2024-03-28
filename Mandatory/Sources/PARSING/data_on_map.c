/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_on_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:53:36 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/28 16:23:45 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	check_data_map(char **map) //1er jet a tester
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
				&& map[i][j] != 32)
				return (1);
		}
	}
	return (0);
}

int	check_char(t_lst *check, t_lst *tmp_map)
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

