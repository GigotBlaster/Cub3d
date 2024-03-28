/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:04:42 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/28 15:06:14 by npetitpi         ###   ########.fr       */
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

