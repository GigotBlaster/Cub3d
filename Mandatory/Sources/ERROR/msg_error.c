/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.msg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:00:15 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/22 13:46:47 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	msg_error(char *s1, char *s2, int ret_val)
{
	if (s1)
		write(STDOUT_FILENO, s1, ft_strlen(s1));
	if (s2)
		write(STDOUT_FILENO, s2, ft_strlen(s2));
	write(STDOUT_FILENO, "\n", 1);
	return (ret_val);
}
