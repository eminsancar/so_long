/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msancar <msancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:08:34 by msancar           #+#    #+#             */
/*   Updated: 2025/12/23 19:18:30 by msancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "so_long.h"
#include <fcntl.h>
#include <unistd.h>

static void	map_height(const char *map, int *height, t_vars *vars)
{
	int		fd;
	int		check;
	char	c;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		exit_and_free("File can not open!", vars);
	check = 1;
	while (check > 0)
	{
		check = read(fd, &c, 1);
		if (check < 0)
			exit_and_free("File read error!", vars);
		if (check > 0 && c == '\n')
			(*height)++;
	}
	close(fd);
	if (*height == 0)
		exit_and_free("Empty Map!", vars);
}

static void	load_map(const char *map, t_vars *vars, int height)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		exit_and_free("File can not open!", vars);
	vars->map->map = malloc(sizeof(char *) * (height + 1));
	if (!vars->map->map)
	{
		close(fd);
		exit_and_free("Malloc allocation failed!", vars);
	}
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		vars->map->map[i] = line;
		i++;
		line = get_next_line(fd);
	}
	vars->map->map[i] = NULL;
	close(fd);
	map_investigation(vars);
}

void	vars_init(const char *map, t_vars **vars)
{
	int	height;

	height = 0;
	(*vars) = ft_calloc(1, sizeof(t_vars));
	if (!*vars)
		exit_and_free("Malloc allocation failed!", NULL);
	(*vars)->map = ft_calloc(1, sizeof(t_map));
	if (!(*vars)->map)
		exit_and_free("Malloc allocation failed!", (*vars));
	map_height(map, &height, (*vars));
	(*vars)->map->height = height;
	load_map(map, (*vars), height);
	if (!(*vars)->map || !(*vars)->map->map)
		exit_and_free("Map loading error!", *vars);
	(*vars)->c_c = index_counter((*vars), 'C');
	if ((*vars)->c_c == 0)
		exit_and_free("Map must contain exactly 1 Collectiable!", *vars);
	(*vars)->temp_c = (*vars)->collectibles;
	(*vars)->temp_e = 1;
	m_scaling(vars);
	p_scaling(vars);
	(*vars)->movement = 0;
}
