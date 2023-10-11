/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/11 13:56:43 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/10/11 17:51:36 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>

/*TODO: remember the last buffer so no characters get lost*/

char *get_next_line(int fd)
{
	static char	*last_buffer;
	char		*buffer;
	char		*str;
	size_t		len;

	buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	str = NULL;
	while (1)
	{
		len = read(fd, buffer, BUFFER_SIZE);
		str = (char *)ft_realloc(str, ft_strlen(str) + len + 1);
		if (str == NULL)
			return (NULL);
		if (ft_strchr(buffer, '\n') != NULL || len == 0)
			break;
		ft_strlcat(str, buffer, ft_strlen(str) + len + 1);
	}
	if (len == 0)
		return (str);
	ft_strlcat(str, buffer, ft_strlen(str) + ft_strchr(buffer, '\n') - buffer + 2);
	last_buffer = buffer;
	return (str);
}

int	main()
{
	int	fd = open("example.txt", O_RDONLY);
	if (fd == -1)
	{
		//printf("crash\n");
		return (0);
	}
	//printf("test\n");
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
