/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:51:49 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/28 14:56:42 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;

	str = s;
	while (n > 0)
	{
		*str = '\0';
		str++;
		n--;
	}
}

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
