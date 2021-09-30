/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 12:32:56 by felcaue-          #+#    #+#             */
/*   Updated: 2021/09/30 16:38:10 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ATENÇÂO AO HEADER

#include "get_next_line.h"
#include <fcntl.h> //DELETE FOR EVALUATION
#include <stdio.h> //DELETE FOR EVALUATION

char	*get_next_line(int fd)
{
	char	*buffer;
	int		read_bytes; //size of bytes read

	read_bytes = 0;
	buffer = NULL;
	if (fd < 0 || read(fd, NULL, 0) == -1 || BUFFER_SIZE < 1 || buffer == NULL)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	buffer[read_bytes] = '\0';
	return (buffer);
}

int		main(void)
{
	char	*str;
	int		fd;

	fd = open("poema", O_RDONLY);
	while(1)
	{
		str = get_next_line(fd);
		if (!str)
			break;
		printf("%s", str);
		//free(str);
		break;
	}
	return (0);
}
