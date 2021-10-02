/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 12:32:56 by felcaue-          #+#    #+#             */
/*   Updated: 2021/10/01 21:56:55 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ATENÇÂO AO HEADER

#include "get_next_line.h"
#include <fcntl.h> //DELETE FOR EVALUATION
#include <stdio.h> //DELETE FOR EVALUATION

static void free_potr_char(char **str)
{
	free (*str);
	*str = NULL;
}

static char	*trim_end_line(char **strin)
{
	char	*cut_line;
	char	*s_holder;
	size_t	counter;

	counter = 0;
	while ((*strin)[counter] && (*strin)[counter] != '\n')
	{
		counter++;
	}
	s_holder = *strin;
	cut_line = ft_substr(s_holder, 0, counter + 1);
	*strin = ft_strdup(&s_holder);
	free_potr_char(&s_holder);
	return (cut_line);
}

char	*hold_text(int fd, char *buffer, char *static_str, int *size_read)
{
	char	*helper;

	while (!ft_strchr(static_str, '\n') && *size_read)
	{
		*size_read = read(fd, buffer, BUFFER_SIZE);
		if (*size_read <= 0)
			break ;
		buffer[*size_read] = '\0';
		helper = static_str;
		static_str = ft_strjoin(helper, buffer);
		free_potr_char(&helper);
	}
	free_potr_char(&buffer);
	return (static_str);
}

char	*get_next_line(int fd)
{
	int			read_bytes; //size of bytes read
	char		*buffer;
	static char	*static_var;

	read_bytes = 0;
	buffer = NULL;
	if (fd < 0 || read(fd, NULL, 0) == -1 || BUFFER_SIZE < 1 || buffer == NULL)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	if (!static_var)
		static_var = ft_strdup("");
	read_bytes = 1;
	static_var = hold_text(fd, buffer, static_var, &read_bytes);
	if (*static_var == NULL && read_bytes < 1)
	{
		free_potr_char(&static_var);
		return(NULL);
	}
	if (ft_strchr(static_var, '\n'))
	{
		return (trim_end_line(static_var));
	}
	return (*static_var);
}

int	main(void)
{
	char	*str;
	int		fd;

	fd = open("poema", O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		printf("%s", str);
		//free(str);
		break ;
	}
	return (0);
}
