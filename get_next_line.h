/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcole <jcole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 13:43:22 by jcole             #+#    #+#             */
/*   Updated: 2026/10/18 15:35:22 by jcole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char	*get_next_line(int fd);

//!----------------utils----------------

char	*my_strchr(const char *str, int c);
int		my_strlen(const char *str);
int		my_strlcpy(char *dest, const char *srce, int num);
char	*my_strjoin(char const *s1, char const *s2);

#endif