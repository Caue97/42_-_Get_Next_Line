/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 12:32:59 by felcaue-          #+#    #+#             */
/*   Updated: 2021/09/30 19:17:01 by felcaue-         ###   ########.fr       */
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

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *strin_g);
void	*ft_memcpy(char *copy, const void *original, size_t length);
size_t	ft_strlcpy(char *copy, const char *original, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *strin, int char_search);

char	*get_next_line(int fd);

#endif