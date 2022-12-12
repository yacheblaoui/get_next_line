/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachebla <yachebla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:08:58 by yachebla          #+#    #+#             */
/*   Updated: 2022/12/07 17:54:46 by yachebla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2023
# endif

size_t	ft_strlen(const char *s);
char	*ft_strchr(char *s, int x);
char	*ft_strjoin(char *s1, char *s2);
char	*end_line(char *line);
char	*read_line(int fd, char *line);
char	*next_line(char *line);
char	*get_next_line(int fd);

#endif