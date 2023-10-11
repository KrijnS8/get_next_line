/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/11 13:56:41 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/10/11 17:05:21 by kschelvi      ########   odam.nl         */
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
		while (i < n)
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

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_size;
	size_t	len;

	i = 0;
	dst_size = ft_strlen(dst);
	if (size <= 0 || dst_size >= size)
		len = ft_strlen(src) + size;
	else
		len = dst_size + ft_strlen(src);
	while (src[i] != '\0' && dst_size + 1 < size)
	{
		dst[dst_size] = src[i];
		dst_size++;
		i++;
	}
	dst[dst_size] = '\0';
	return (len);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		ptr[i] = c;
		i++;
	}
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if ((int) nmemb < 0 && (int) size < 0)
		return (NULL);
	if (nmemb * size > 4294967295)
		return (NULL);
	ptr = malloc (nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, '\0', nmemb * size);
	return (ptr);
}

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
		return (ft_calloc(size, sizeof(char)));
	new_ptr = ft_calloc(size, sizeof(char));
	if (new_ptr == NULL)
		return (NULL);
	ft_memcpy(new_ptr, ptr, ft_strlen((char *)ptr));
	free(ptr);
	return (new_ptr);
}
