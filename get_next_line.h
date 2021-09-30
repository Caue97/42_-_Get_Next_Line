/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 12:32:59 by felcaue-          #+#    #+#             */
/*   Updated: 2021/09/30 14:04:53 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ATENÇÂO AO HEADER

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "get_next_line.h"

# include <stdlib.h>
# include <unistd.h> 

char	*get_next_line(int fd);

#endif