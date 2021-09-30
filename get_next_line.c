/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diazeved <contato.diegoazevedo@gmail.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 12:32:56 by felcaue-          #+#    #+#             */
/*   Updated: 2021/09/30 13:51:14 by diazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h> //DELETE FOR EVALUATION
#include <stdio.h> //DELETE FOR EVALUATION

	

char	*get_next_line(int fd)
{
	char	*buffer;
	ssize_t	read_bytes;

	read_bytes = 0;
	buffer = NULL;
	if (fd < 0 || read(fd, NULL, 0) == -1 || BUFFER_SIZE < 1 || buffer == NULL)
		return (NULL);

	read_bytes = read(fd, buffer, BUFFER_SIZE);
	buffer[read_bytes] = '\0';
	return(buffer);
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
