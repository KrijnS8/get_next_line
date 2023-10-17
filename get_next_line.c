/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/16 13:24:51 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/10/17 17:28:46 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include "get_next_line.h"

bool	ft_add_to_line(char **line, char *buffer)
{
	char	*tmp;

	tmp = ft_strjoin(*line, buffer);
	if (tmp == NULL)
		return (false);
	free(*line);
	*line = tmp;
	return (true);
}

char	*ft_add_to_line_newline(char **line, char *buffer, char **remainder)
{
	char	*tmp;
	char	*substr;
	char	*ptr;

	ptr = ft_strchr(buffer, '\n') + 1;
	*remainder = ft_strdup(ptr, ft_strlen(ptr));
	if (remainder == NULL)
		return (NULL);
	substr = ft_substr(buffer, 0, ft_strchr(buffer, '\n') - buffer + 1);
	if (substr == NULL)
		return (NULL);
	tmp = ft_strjoin(*line, substr);
	if (tmp == NULL)
	{
		free(substr);
		return (NULL);
	}
	free(*line);
	free(substr);
	free(buffer);
	*line = tmp;
	return (*line);
}

char	*ft_init_buffer(char **buffer, char **remainder, \
						size_t *bytes_read, int fd)
{
	if (*remainder != NULL)
	{
		*buffer = ft_strdup(*remainder, (size_t)BUFFER_SIZE);
		if (*buffer == NULL)
			return (NULL);
		free(*remainder);
		*remainder = NULL;
		*bytes_read = 1;
	}
	else
	{
		*buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (*buffer == NULL)
			return (NULL);
		*bytes_read = read(fd, *buffer, BUFFER_SIZE);
		if ((int)*bytes_read < 0)
			return (free(*buffer), NULL);
		(*buffer)[*bytes_read] = '\0';
	}
	return (*buffer);
}

char	*get_next_line(int fd)
{
	static char	*remainder = NULL;
	char		*buffer;
	char		*line;
	size_t		bytes_read;

	line = NULL;
	if (ft_init_buffer(&buffer, &remainder, &bytes_read, fd) == NULL)
		return (NULL);
	while (bytes_read > 0 && ft_strchr(buffer, '\n') == NULL)
	{
		if (!ft_add_to_line(&line, buffer))
			return (NULL);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if ((int)bytes_read < 0)
			return (free(buffer), free(line), NULL);
		buffer[bytes_read] = '\0';
	}
	if (ft_strchr(buffer, '\n') != NULL)
		return (ft_add_to_line_newline(&line, buffer, &remainder));
	if (!ft_add_to_line(&line, buffer))
		return (free(buffer), free(remainder), NULL);
	if (*line == '\0' && remainder == NULL)
		return (free(buffer), free(line), NULL);
	return (free(buffer), line);
}

/* #include <fcntl.h>

int	main(void)
{
	int fd = open("./gnlTester/files/big_line_no_nl", O_RDONLY);
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
}
 */