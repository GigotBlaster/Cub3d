/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <lcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:44:58 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/12 14:03:29 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub.h"

int main(int ac, char **av)
{
	t_env *env;

	(void)ac;
	env = (t_env *)malloc(sizeof(t_env));
	env->map = ft_map_init();
	env->map = ft_fill_grid(env, av[1]);
	ft_free_map(env->map);
	return (0);
}
