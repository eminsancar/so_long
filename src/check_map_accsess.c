/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_accsess.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msancar <msancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:59:04 by msancar           #+#    #+#             */
/*   Updated: 2025/12/23 16:43:39 by msancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "so_long.h"

char	**clone_map(t_vars *vars)
{
	char	**clone;
	int		i;

	i = 0;
	clone = malloc(sizeof(char *) * (vars->map->m_height + 1));
	if (!clone)
		exit_and_free("Couldn't creat clone map!", vars);
	while (i < vars->map->m_height)
	{
		clone[i] = ft_strdup(vars->map->map[i]);
		if (!clone[i])
			exit_and_free("Couldn't creat clone map!", vars);
		i++;
	}
	clone[i] = NULL;
	return (clone);
}

void	flood_fill(char **clone, int y, int x, t_vars *vars)
{
	int		w;

	if (y < 0 || y >= vars->map->m_height)
		return ;
	w = (int)ft_strlen(clone[y]);
	if (x < 0 || x >= w)
		return ;
	if (clone[y][x] == '1' || clone[y][x] == 'L')
		return ;
	clone[y][x] = 'L';
	flood_fill(clone, y + 1, x, vars);
	flood_fill(clone, y - 1, x, vars);
	flood_fill(clone, y, x + 1, vars);
	flood_fill(clone, y, x - 1, vars);
}

static void	free_clone_map(char **clone)
{
	int	i;

	i = 0;
	while (clone[i])
	{
		free(clone[i]);
		i++;
	}
	free(clone);
}

void	check_clone_acsess(char **clone, t_vars *vars)
{
	int		y;
	int		x;

	y = 0;
	while (clone[y])
	{
		x = 0;
		while (clone[y][x])
		{
			if (clone[y][x] == 'C' || clone[y][x] == 'E')
			{
				free_clone_map(clone);
				exit_and_free("The map is not suitable!", vars);
			}
			x++;
		}
		y++;
	}
}

void	check_map_acces(t_vars *vars)
{
	char	**clone;

	clone = clone_map(vars);
	flood_fill(clone, vars->p_height, vars->p_width, vars);
	check_clone_acsess(clone, vars);
	free_clone_map(clone);
}
