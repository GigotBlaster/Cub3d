/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_on_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:53:36 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/22 15:57:38 by npetitpi         ###   ########.fr       */
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
				&& map[i][j] != 32 && map[i][j] != 'N' && map[i][j] != '\n')
				return (1);
		}
	}
	return (0);
}

