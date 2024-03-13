/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:32:22 by lcadinot          #+#    #+#             */
/*   Updated: 2024/03/13 13:33:42 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
