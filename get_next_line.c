/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachebla <yachebla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:09:13 by yachebla          #+#    #+#             */
/*   Updated: 2022/12/09 11:46:19 by yachebla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *line)
{
	char	*str;
	int		bytes;

	str = malloc(BUFFER_SIZE + 1 * sizeof(char ));
	if (!str)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(line, '\n') && bytes != 0)
	{
		bytes = read(fd, str, BUFFER_SIZE);
		if (bytes == -1)
			return (free(str), free(line), NULL);
		str[bytes] = '\0';
		line = ft_strjoin(line, str);
	}
	return (free(str), line);
}

char	*end_line(char *line)
{
	char	*str;
	int		i;

	i = 0;
	if (*line == 0)
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	str = (char *)malloc(i + 1 * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		str[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*next_line(char *line)
{
	char	*str;
	int		j;
	int		i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\0')
		return (free(line), NULL);
	str = (char *)malloc((ft_strlen(line) - i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (line[i])
	{
		str[j] = line[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (free(line), str);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*final;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_line(fd, line);
	if (!line)
		return (NULL);
	final = end_line(line);
	line = next_line(line);
	return (final);
}
