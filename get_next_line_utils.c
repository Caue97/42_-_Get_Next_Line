/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 12:32:50 by felcaue-          #+#    #+#             */
/*   Updated: 2021/09/30 19:15:45 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ATENÇÂO AO HEADER

#include "get_next_line.h"

void	*ft_memcpy(char *copy, const void *original, size_t length)
{
	unsigned char	*source;
	unsigned char	*destiny;

	if (original == NULL && copy == NULL)
	{
		return (copy);
	}
	destiny = (unsigned char *) copy;
	source = (unsigned char *) original;
	while (length--)
	{
		*destiny++ = *source++;
	}
	return (copy);
}

size_t	ft_strlen(const char *str)
{
	size_t	n_d_letras;

	if (str == NULL)
	{
		return (0);
	}
	n_d_letras = 0;
	while (str[n_d_letras] != '\0')
	{
		n_d_letras++;
	}
	return (n_d_letras);
}

char	*ft_strdup(const char *strin_g)
{
	size_t	length;
	char	*new_cpy;

	length = ft_strlen(strin_g) + 1;
	new_cpy = malloc(length);
	if (!new_cpy)
	{
		return (0);
	}
	return (ft_memcpy(new_cpy, strin_g, length));
}

size_t	ft_strlcpy(char *copy, const char *original, size_t size)
{
	size_t	size_og;
	size_t	counter;

	size_og = ft_strlen(original);
	counter = 0;
	if (!original || !copy)
	{
		return (0);
	}
	if (size != 0)
	{
		while (original[counter] != '\0' && counter < (size - 1))
		{
			copy[counter] = original[counter];
			counter++;
		}
		copy[counter] = '\0';
	}
	return (size_og);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_strng;
	size_t	size_og;

	size_og = ft_strlen(s);
	if (!s)
	{
		return (0);
	}
	if (start > size_og)
	{
		return (ft_strdup(""));
	}
	sub_strng = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub_strng)
	{
		return (0);
	}
	ft_strlcpy(sub_strng, (s + start), len + 1);
	sub_strng[len] = '\0';
	return (sub_strng);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strng_u;
	char	*destiny_ret;

	if (!s1 || !s2)
	{
		return (NULL);
	}
	strng_u = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)
				+ 1) * sizeof(char));
	if (strng_u == NULL)
	{
		return (NULL);
	}
	destiny_ret = strng_u;
	while (*s1)
	{
		*strng_u++ = *s1++;
	}
	while (*s2)
	{
		*strng_u++ = *s2++;
	}
	*strng_u = '\0';
	return (destiny_ret);
}

char	*ft_strchr(const char *strin, int char_search)
{
	if (char_search > 127)
	{
		char_search %= 256;
	}
	while (*strin)
	{
		if (*strin == char_search)
		{
			return ((char *)strin);
		}
		strin++;
	}
	if (*strin == char_search)
	{
		return ((char *)strin);
	}
	return (NULL);
}
