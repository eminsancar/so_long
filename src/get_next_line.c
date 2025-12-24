/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msancar <msancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:06:19 by msancar           #+#    #+#             */
/*   Updated: 2025/12/17 13:06:35 by msancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "so_long.h"
#include <unistd.h>

static char	*ft_read_2(int fd, char *str, char *buffer)
{
	int		buf_read;
	char	*tmp;

	buf_read = 1;
	while (!ft_strchr(str, '\n') && buf_read != 0)
	{
		buf_read = read(fd, buffer, BUFFER_SIZE);
		if (buf_read == -1)
		{
			free(buffer);
			free(str);
			return (NULL);
		}
		buffer[buf_read] = '\0';
		tmp = str;
		str = ft_strjoin(str, buffer);
		free(tmp);
		if (!str)
		{
			free(buffer);
			return (NULL);
		}
	}
	free(buffer);
	return (str);
}

static char	*ft_read(int fd, char *str)
{
	char	*buffer;

	if (!str)
		str = ft_strdup("");
	if (!str)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(str);
		return (NULL);
	}
	return (ft_read_2(fd, str, buffer));
}

static char	*ft_after_nl(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	tmp = malloc(ft_strlen(str) - i + 1);
	if (!tmp)
	{
		free(str);
		str = NULL;
		return (str);
	}
	if (str[i] == '\n')
		i++;
	ft_strlcpy(tmp, str + i, ft_strlen(str + i) + 1);
	free(str);
	return (tmp);
}

static char	*ft_before_nl(char *str)
{
	int		i;
	char	*tmp;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	tmp = malloc(i + 1);
	if (!tmp)
		return (NULL);
	i = 0;
	if (!str[0])
		return (free(tmp), NULL);
	while (str[i] && str[i] != '\n')
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char		*str = NULL;
	char			*result;

	if (fd == -1 || BUFFER_SIZE <= 0)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	str = ft_read(fd, str);
	if (!str)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	result = ft_before_nl(str);
	str = ft_after_nl(str);
	return (result);
}
