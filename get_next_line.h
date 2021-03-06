/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 12:32:59 by felcaue-          #+#    #+#             */
/*   Updated: 2021/10/02 00:20:32 by felcaue-         ###   ########.fr       */
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

/**
 * @brief Computes the length of the string s up to, but not including the
 * terminating null character. Example: ft_strlen("1234") => 4
 *
 * @param str This is the string whose length is to be found.
 * @return This function returns the length of string.
 */
size_t	ft_strlen(const char *str);

/**
 * @brief Returns a pointer to a null-terminated byte string, which is a
 * duplicate of the string pointed to by str. The returned pointer must be
 * passed to free to avoid a memory leak. If an error occurs, a null pointer
 * is returned and errno may be set.
 *
 * @param strin_g Pointer to the null-terminated byte string to duplicate.
 * @return A pointer to the newly allocated string, or a null pointer
 * if an error occurred.
 */
char	*ft_strdup(const char *strin_g);

/**
 * @brief Allocates (with malloc(3)) and returns a substring from the string
 * ’s’. The substring begins at index ’start’ and is of maximum size ’len’.
 *
 * @param strin The string from which to create the substring.
 * @param start The start index of the substring in the string ’s’.
 * @param len The maximum length of the substring.
 * @return The substring. NULL if the allocation fails.
 */
char	*ft_substr(char const *strin, unsigned int start, size_t len);

/**
 * @brief Allocates (with malloc(3)) and returns a new string, which is the
 * result of the concatenation of ’s1’ and ’s2’.
 *
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * @return The new string. NULL if the allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Searches for the first occurrence of the character c
 * (an unsigned char) in the string pointed to by the argument s. The
 * terminating null	character is considered	part of	the string; therefore
 * if c is \\0, the functions locate the terminating \\0.
 *
 * @param strin This is the C string to be scanned.
 * @param char_search This is the character to be located. It is passed as int,
 * but it is internally converted back to char.
 * @return This returns a pointer to the first occurrence of the character c
 * in the string s, or NULL if the character is not found.
 */
char	*ft_strchr(const char *strin, int char_search);

/**
 * @brief Reads the file descriptor from a BUFFER_SIZE piece to another 
 * until a piece that has '\\n' is found or until the end of the file.
 *
 * @param fd File descriptor that will be read and searched for '\\n'.
 * @param buffer Holds the text that was read in BUFFER_SIZE
 * @param static_str The static string that will hold the line
 * @param size_read The size that was red from file descriptor
 * @return The part of the file that was read 
 */
char	*read_until_new_line(int fd, char *buffer, char *s_str, int *size_read);

/**
 * @brief Reads a line from a file descriptor
 *
 * @param fd File descriptor to read.
 * @return The line that was read, including '\\n', if it has multiple lines.
 * The line read without '\\n' if the file has only one line.
 * NULL if the file is empty or an error ocurred
 */
char	*get_next_line(int fd);

#endif