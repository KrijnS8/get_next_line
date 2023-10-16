/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/16 13:24:51 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/10/16 17:27:24 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*remainder = NULL;
	char		*buffer;
	char		*line;
	char		*tmp;
	size_t		bytes_read;

	buffer = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	line = NULL;
	if (buffer == NULL)
		return (NULL);
	if (remainder != NULL)
		line = ft_strdup(remainder);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0 && ft_strchr(buffer, '\n') == NULL)
	{
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin(line, buffer);
		free(line);
		line = tmp;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (ft_strchr(buffer, '\n') != NULL)
	{
		tmp = ft_strchr(buffer, '\n');
		remainder = ft_strdup(tmp + 1);
		*tmp = '\0';
		
	}
	tmp = ft_strjoin(line, buffer);
	free(line);
	line = tmp;
	free(buffer);
	return (line);
}


#include <fcntl.h>

int	main(void)
{
	int fd = open("example.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}