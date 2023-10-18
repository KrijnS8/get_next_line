/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/16 13:21:43 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/10/18 12:55:11 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 12
# endif
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *s, size_t size);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char	*s, unsigned int start, size_t len);
size_t	ft_strlen(char *str);

#endif
