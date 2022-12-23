/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 10:34:14 by terussar          #+#    #+#             */
/*   Updated: 2022/12/23 15:18:15 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*loop(int fd)
{
	char	buf[BUFFER_SIZE + 1];
	int	size;
	char	*s;

	size = 1;
	s = "";
	while (size && find_new_line(buf) == 0)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size < 1)
			return (NULL);
		buf[size] = '\0';
		s = ft_strjoin(s, buf);
	}
	return (s);
}

char	*get_line(char *s)
{
	char	*line;

	if (!s)
		return (NULL);
	line = ft_strndown(s, find_new_line(s));
	return (line);
}

char	*keep_line(char *s)
{
	char	*tmp;

	if (s == NULL)
		return (NULL);
	tmp = ft_strndup(s, find_new_line(s));
	free(s);
	s = ft_strndown(tmp, ft_strlen(tmp));
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char	*line;
	char	*tmp;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	if (s != NULL)
		tmp = ft_strndown(s, ft_strlen(s));
	else
		tmp = NULL;
	s = loop(fd);
	if (s == NULL)
	{
		if (tmp == NULL)
			return (NULL);
		return (tmp);
	}
	line = get_line(s);
	s = keep_line(s);
	line = ft_strjoin(tmp, line);
	return (line);
}

// int	main()
// {
// 	int			fd;
// 	char 	*str;

// 	fd = open("test.txt", O_RDONLY);
// 	// str = loop(fd);
// 	// printf("%s", str);
// 	while ((str = get_next_line(fd)))
// 	{
// 		printf("%s", str);
// 		free(str);
// 	}
// 	// str = get_next_line(fd);
// 	// printf("%s", str);
// 	free(str);
// 	close(fd);
// }
