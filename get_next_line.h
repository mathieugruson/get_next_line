/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:06:12 by ilandols          #+#    #+#             */
/*   Updated: 2023/01/06 13:19:58 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <fcntl.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE	5
# endif

int is_end_of_line(char *str);
char *get_line(char *line, char *buffer);
char *get_next_line(int fd);

/* get_next_line_utils.c */

char *ft_strjoin(char *line, char *buffer);
char *ft_strdup(char *str);
int ft_strlen(char *str);

#endif
