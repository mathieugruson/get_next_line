/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:48:28 by mgruson           #+#    #+#             */
/*   Updated: 2023/01/06 13:24:48 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int is_end_of_line(char *str)
{
	int i = 0;
	
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char *get_line(char *line, char *buffer)
{
	int i = 0;
	int j = 0;
	if (!line)
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	while(line[i])
	{
		buffer[j] = line[i];
		line[i] = '\0';
		j++;
		i++;
	}
	return (line);
}

char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1];
	char *line;
	static int rd = 0;
	
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	if (rd > 0 && buffer[0])
		line = ft_strdup(buffer);
	rd = BUFFER_SIZE;
	while(!is_end_of_line(line) && rd == BUFFER_SIZE)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd > 0)
			line = ft_strjoin(line, buffer);
	}
	line = get_line(line, buffer);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*str = "start";
	int i = 0;
	
	fd = open("get_next_line.c", O_RDONLY);
	printf("%s\n", str);
	while(i < 80)
	{
		str = get_next_line(fd);
		printf("%s", str);
		i++;
	}
	return (0);
}