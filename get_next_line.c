/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 12:32:56 by felcaue-          #+#    #+#             */
/*   Updated: 2021/10/01 18:09:56 by felcaue-         ###   ########.fr       */
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
	
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	buffer[read_bytes] = '\0';
	return (buffer);
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
