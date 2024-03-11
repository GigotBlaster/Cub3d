/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:52:02 by npetitpi          #+#    #+#             */
/*   Updated: 2024/03/11 16:52:06 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*ft_read_line(int fd, char *line)
{
	char	*buff;
	int		byte_readed;

	buff = ft_calloc((BUFFER_SIZE + 1), 1);
	if (!buff)
		return (NULL);
	byte_readed = 1;
	while ((!ft_strchr(line, '\n') || !ft_strchr(line, '\n'))
		&& byte_readed != 0)
	{
		byte_readed = read(fd, buff, BUFFER_SIZE);
		if (byte_readed == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[byte_readed] = '\0';
		line = ft_strjoin(line, buff);
	}
	free (buff);
	return (line);
}

char	*get_next_line(int fd, int reset)
{
	char		*buff;
	static char	*line;

	if (reset)
		return (free(line), NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line = ft_read_line(fd, line);
	if (!line)
		return (NULL);
	buff = ft_line_to_buff(line);
	line = ft_read_new_line(line);
	return (buff);
}
