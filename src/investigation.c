/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   investigation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msancar <msancar@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:09:58 by msancar           #+#    #+#             */
/*   Updated: 2025/12/17 13:09:59 by msancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "so_long.h"

static void	check_top_wall(t_vars *vars)
{
	int	j;

	j = 0;
	while (vars->map->map[0][j])
	{
		if (vars->map->map[0][j] != '1')
			exit_and_free("Map not surrended by walls!", vars);
		j++;
	}
}

void	map_investigation(t_vars *vars)
{
	unsigned int	width;
	int				last_i;

	width = ft_strlen(vars->map->map[0]);
	check_top_wall(vars);
	last_i = check_middle_rows(vars, width);
	check_player_exit_count(vars);
	check_bottom_wall(vars, last_i);
}
