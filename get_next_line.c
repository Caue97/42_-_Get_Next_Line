/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diazeved <contato.diegoazevedo@gmail.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 12:32:56 by felcaue-          #+#    #+#             */
/*   Updated: 2021/09/30 13:15:45 by diazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h> //DELETE FOR EVALUATION

char	*get_next_line(int fd)
{
	
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
		free(str);
		break;
	}
	return (0);
}
