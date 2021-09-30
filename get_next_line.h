/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diazeved <contato.diegoazevedo@gmail.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 12:32:59 by felcaue-          #+#    #+#             */
/*   Updated: 2021/09/30 13:09:43 by diazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "get_next_line.h"

char	*get_next_line(int fd);

#endif