/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcole <jcole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 13:42:53 by jcole             #+#    #+#             */
/*   Updated: 2026/10/18 15:49:33 by jcole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *saved)
{
	int		i;
	int		slen;
	char	*line;

	i = 0;
	while (saved[i] != '\0' && saved[i] != '\n')
		i++;
	if (saved[i] == '\n')
		slen = i + 2;
	else
		slen = i + 1;
	line = malloc(slen);
	if (!line)
		return (NULL);
	my_strlcpy(line, saved, slen);
	return (line);
}

char	*updated_saved(char *saved)
{
	int		i;
	int		remaining;
	char	*temp;

	i = 0;
	while (saved[i] != '\0' && saved[i] != '\n')
		i++;
	if (saved[i] == '\n')
	{
		remaining = my_strlen(saved + i + 1) + 1;
		temp = malloc(remaining);
		if (!temp)
			return (NULL);
		my_strlcpy(temp, saved + i + 1, remaining);
		free(saved);
		saved = temp;
	}
	else
	{
		free(saved);
		saved = NULL;
	}
	return (saved);
}

static int	read_to_saved(int fd, char **saved)
{
	char	*buffer;
	char	*temp;
	int		count;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	count = 1;
	while ((!*saved || !my_strchr(*saved, '\n')) && count != 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == -1)
			break ;
		buffer[count] = '\0';
		temp = my_strjoin(*saved, buffer);
		free(*saved);
		*saved = temp;
		if (!*saved)
			break ;
	}
	free(buffer);
	return (count);
}

char	*get_next_line(int fd)
{
	static char	*saved;
	char		*line;

	if (read_to_saved(fd, &saved) == -1 || !saved || !saved[0])
	{
		free(saved);
		saved = NULL;
		return (NULL);
	}
	line = extract_line(saved);
	saved = updated_saved(saved);
	return (line);
}
