/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:07:42 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/14 13:40:51 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	name_ok(char *file, char *str)
{
	int	len;

	len = ft_strlen(file);
	if (file[len - 4] != str[0] || file[len - 3] != str[1] 
		|| file[len - 2] != str[2] || file[len - 1] != str[3])
		return (1);
	return (0);
}

int	map_ok(t_data *game, char *file)
{
	int	fd;

	if (name_ok(file, ".cub"))
		return (err_msg(file, NO_CUB, 1));
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (err_msg(file, OPEN, 2));
	//init map
	// Close fd
	// Check et open textures
	// Check wall 
	return(0);
}