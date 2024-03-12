/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <lcadinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:32:22 by lcadinot          #+#    #+#             */
/*   Updated: 2024/03/12 12:14:16 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dest;

	if (nmemb > 0 && SIZE_MAX / size < nmemb)
		return (NULL);
	dest = malloc(nmemb * size);
	if (!dest)
		return (NULL);
	ft_bzero(dest, nmemb * size);
	return (dest);
}
