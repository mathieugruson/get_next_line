/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:43:51 by mgruson           #+#    #+#             */
/*   Updated: 2023/01/06 13:16:20 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *str)
{
	int i = 0;
	
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char *ft_strjoin(char *line, char *buffer)
{
	char *res;
	int i = 0;
	int j = 0;
	
	res = malloc(ft_strlen(line) + ft_strlen(buffer) + 1);
	while(line && line[i])
	{	
		res[i] = line[i];
		i++;
	}
	while(buffer && buffer[j])
	{
		res[i] = buffer[j];
		buffer[j] = '\0';
		i++;
		j++;
	}
	res[i] = '\0';
	if (line)
		free(line);
	return (res);
}

char *ft_strdup(char *str)
{
	int i = 0;
	char *res;
	
	if (!str)
		return (NULL);
	res = malloc(ft_strlen(str) + 1);
	while(str[i])
	{
		res[i] = str[i];
		str[i] = '\0';
		i++;
	}
	res[i] = '\0';
	return (res);
}