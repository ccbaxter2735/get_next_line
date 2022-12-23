/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 10:34:52 by terussar          #+#    #+#             */
/*   Updated: 2022/12/22 17:17:13 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	find_new_line(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (-1);
	while (s[i] && s[i] != '\n')
		i++;
	if (i != ft_strlen(s))
		return (i + 1);
	return (0);
}

char	*ft_strndown(char *src, int pos)
{
	int		i;
	char	*dest;

	dest = malloc((pos + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < pos)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strndup(char *src, int pos)
{
	int		i;
	char	*dest;
	int		l;

	l = ft_strlen(src) - pos;
	dest = malloc((l + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[pos] != '\0')
	{
		dest[i] = src[pos];
		i++;
		pos++;
	}
	dest[i] = '\0';
	return (dest);//free (src)
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*dest;

	if (s1 == NULL)
		return (s2);
	dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		dest[i++] = s2[j];
		j++;
	}
	dest[i] = 0;
	return (dest);
}

// int main()
// {
// 	char *s1 = NULL;
// 	char *s2 = "je suis";

// 	printf("%s\n", ft_strjoin(s1, s2));
// }