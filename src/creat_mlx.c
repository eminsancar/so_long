/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msancar <msancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:03:05 by msancar           #+#    #+#             */
/*   Updated: 2025/12/23 16:50:07 by msancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include <stdlib.h>

void	init_mlx(t_vars *vars)
{
	int		win_w;
	int		win_h;

	win_h = vars->map->m_height * 48;
	win_w = vars->map->m_width * 48;
	vars->mlx = mlx_init();
	if (!vars->mlx)
		exit_and_free("MLX could not be initialized!", vars);
	vars->win = mlx_new_window (vars->mlx, win_w, win_h, "so_long");
	if (images(vars))
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit_and_free("Photos could not be created!", vars);
	}
}

int	new_mlx(t_vars *vars)
{
	render_map(vars);
	mlx_put_image_to_window (vars->mlx, vars->win, vars->img.player,
		vars->p_width * 48, vars->p_height * 48);
	return (0);
}
