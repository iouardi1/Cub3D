/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 04:24:55 by iouardi           #+#    #+#             */
/*   Updated: 2023/01/08 04:29:29 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_lib.h"

char	*ft_readline(char *str, char *buffer, int fd)
{
	char	*temp;
	int		buffer_len;

	temp = NULL;
	buffer_len = 1;
	if (!str)
		str = ft_strdup1("");
	while (buffer_len > 0 && !ft_strchr1(str, '\n'))
	{
		buffer_len = read(fd, buffer, BUFFER_SIZE);
		buffer[buffer_len] = '\0';
		temp = ft_strjoin2(str, buffer);
		free(str);
		str = temp;
	}
	return (str);
}

char	*ft_strdup1(const char *s1)
{
	char	*s2;

	s2 = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (s2 == NULL)
		return (NULL);
	ft_memcpy1(s2, s1, sizeof(char) * (ft_strlen(s1) + 1));
	return (s2);
}

char	*get_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	line = malloc((++i + 1) * sizeof(char));
	ft_memcpy1(line, str, i);
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*str;
	char		*line;
	size_t		buffer_len;
	char		*temp;

	line = NULL;
	temp = NULL;
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, buffer, 0) == -1)
		return (NULL);
	buffer_len = 1;
	str = ft_readline(str, buffer, fd);
	line = get_line(str);
	if (ft_strchr1(str, '\n'))
		temp = ft_strdup1(ft_strchr1(str, '\n'));
	free(str);
	str = temp;
	if (!ft_strlen(line))
		return (free(str), free(line), NULL);
	return (line);
}
