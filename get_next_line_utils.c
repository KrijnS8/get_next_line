/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/11 13:56:41 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/10/12 15:53:56 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (i <= (int)ft_strlen(s))
	{
		if (s[i] == (unsigned char)c)
			return (&((char *)s)[i]);
		i++;
	}
	return (NULL);
}

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	int	i;

	if (dst == NULL || src == NULL)
		return (NULL);
	if ((char *)dst > (char *)src && (char *)dst < (char *)src + n)
	{
		i = n - 1;
		while (i >= 0)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)n)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dst);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	int		i;

	if ((int) nmemb < 0 && (int) size < 0)
		return (NULL);
	if (nmemb * size > 4294967295)
		return (NULL);
	ptr = malloc (nmemb * size);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while ((size_t)i < nmemb * size)
	{
		((unsigned char *)ptr)[i] = '\0';
		i++;
	}
	return (ptr);
}

char	*ft_strjoin_and_realloc(char *s1_to_free, char *s2_to_join, size_t s2_size)
{
	size_t	len;
	char	*str;

	len = ft_strlen(s1_to_free) + s2_size;
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s1_to_free, ft_strlen(s1_to_free));
	ft_memcpy(str + ft_strlen(s1_to_free), s2_to_join, s2_size);
	free(s1_to_free);
	return(str);
}
