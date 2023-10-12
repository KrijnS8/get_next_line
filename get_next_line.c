/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/11 13:56:43 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/10/12 15:54:15 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>

/*TODO: Fix all leaks*/

char	*ft_strtrim(char *str, char c)
{
	char	*ptr;
	char	*c_ptr;

	c_ptr = ft_strchr(str, c) + 1;
	ptr = (char *)ft_calloc(ft_strlen(c_ptr) + 1, sizeof(char));
	ft_memcpy(ptr, c_ptr, ft_strlen(c_ptr));
	return (ptr);
}

char *get_next_line(int fd)
{
	static char	*last_buffer = NULL;
	char		*buffer;
	char		*str;
	size_t		len;

	str = NULL;
	if (last_buffer != NULL)
		str = ft_strtrim(last_buffer, '\n');
	buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	while (1)
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (ft_strchr(buffer, '\n') != NULL || len == 0)
			break;
		str = ft_strjoin_and_realloc(str, buffer, len);
		if (str == NULL)
			return (NULL);
	}
	if (len == 0)
		return (str);
	str = ft_strjoin_and_realloc(str, buffer, ft_strchr(buffer, '\n') - buffer + 1);
	last_buffer = (char *)ft_calloc(len + 1, sizeof(char));
	ft_memcpy(last_buffer, buffer, len);
	free(buffer);
	return (str);
}

/* int	main()
{
	int	fd = open("example.txt", O_RDONLY);
	if (fd == -1)
	{
		return (0);
	}
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
 */