/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcole <jcole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 13:43:26 by jcole             #+#    #+#             */
/*   Updated: 2026/10/18 15:49:30 by jcole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	my_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*my_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)c)
			return ((char *)&str[i]);
		i++;
	}
	if ((str[i] == '\0') && (str[i] == (unsigned char)c))
		return ((char *)&str[i]);
	return (NULL);
}

char	*my_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		s1len;
	int		s2len;
	char	*newstr;

	s1len = my_strlen(s1);
	s2len = my_strlen(s2);
	i = 0;
	newstr = malloc((s1len + s2len) + 1);
	if (!newstr)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		newstr[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		newstr[i + s1len] = s2[i];
		i++;
	}
	newstr[i + s1len] = '\0';
	return (newstr);
}

int	my_strlcpy(char *dest, const char *srce, int num)
{
	int	i;

	i = 0;
	if (num == 0)
		return (my_strlen(srce));
	while (srce[i] != '\0' && i < num - 1)
	{
		dest[i] = srce[i];
		i++;
	}
	dest[i] = '\0';
	return (my_strlen(srce));
}
