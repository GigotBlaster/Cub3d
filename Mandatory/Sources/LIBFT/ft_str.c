/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:49:56 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/28 15:00:30 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*ft_strcpy(char *dest, char *src)  //FULL MAP_UTILS A GARDER ?
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *str)	//FULL MAP_UTILS A GARDER ?
{
	char	*dest;
	int		lenght;
	int		i;

	i = 0;
	lenght = ft_strlen(str);
	dest = malloc(sizeof(char) * (lenght + 1));
	if (!dest)
		return (NULL);
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
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

