/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msancar <msancar@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:04:50 by msancar           #+#    #+#             */
/*   Updated: 2025/12/17 13:04:55 by msancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "so_long.h"

void	check_row_rect_and_sides(t_vars *vars, int i, unsigned int width)
{
	if (ft_strlen(vars->map->map[i]) != width)
		exit_and_free("Map not rectangular!", vars);
	if (vars->map->map[i][0] != '1' || vars->map->map[i][width - 1] != '1')
		exit_and_free("Map not surrended by walls!", vars);
}

void	check_row_chars(t_vars *vars, int i)
{
	int	j;

	j = 0;
	while (vars->map->map[i][j])
	{
		if (vars->map->map[i][j] != '1' && vars->map->map[i][j] != '0'
			&& vars->map->map[i][j] != 'P' && vars->map->map[i][j] != 'E'
			&& vars->map->map[i][j] != 'C')
			exit_and_free("Error: Unsuitable character!", vars);
		j++;
	}
}

int	check_middle_rows(t_vars *vars, unsigned int width)
{
	int	i;

	i = 1;
	while (vars->map->map[i])
	{
		check_row_rect_and_sides(vars, i, width);
		check_row_chars(vars, i);
		i++;
	}
	return (i);
}

void	check_player_exit_count(t_vars *vars)
{
	if (index_counter(vars, 'P') != 1 || index_counter(vars, 'E') != 1)
		exit_and_free("Map must contain exactly 1 Player or 1 Exit!", vars);
}

void	check_bottom_wall(t_vars *vars, int last_i)
{
	int	j;

	j = 0;
	while (vars->map->map[last_i - 1][j])
	{
		if (vars->map->map[last_i - 1][j] != '1')
			exit_and_free("Map not surrended by walls!", vars);
		j++;
	}
}
