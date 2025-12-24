/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msancar <msancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:07:15 by msancar           #+#    #+#             */
/*   Updated: 2025/12/23 19:04:47 by msancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

static int	destroy_image(t_vars *vars, int flag)
{
	if (flag > 0)
		mlx_destroy_image(vars->mlx, vars->img.wall);
	if (flag > 1)
		mlx_destroy_image(vars->mlx, vars->img.player);
	if (flag > 2)
		mlx_destroy_image(vars->mlx, vars->img.floor);
	if (flag > 3)
		mlx_destroy_image(vars->mlx, vars->img.exit);
	return (1);
}

int	images(t_vars *vars)
{
	vars->img.wall = mlx_xpm_file_to_image(vars->mlx, "textures/wall.xpm",
			&vars->img.img_h, &vars->img.img_w);
	if (!vars->img.wall)
		return (1);
	vars->img.player = mlx_xpm_file_to_image(vars->mlx, "textures/player.xpm",
			&vars->img.img_h, &vars->img.img_w);
	if (!vars->img.player)
		return (destroy_image(vars, 1));
	vars->img.floor = mlx_xpm_file_to_image(vars->mlx, "textures/floor.xpm",
			&vars->img.img_h, &vars->img.img_w);
	if (!vars->img.floor)
		return (destroy_image(vars, 2));
	vars->img.exit = mlx_xpm_file_to_image(vars->mlx, "textures/exit.xpm",
			&vars->img.img_h, &vars->img.img_w);
	if (!vars->img.exit)
		return (destroy_image(vars, 3));
	vars->img.colletibiles = mlx_xpm_file_to_image(
			vars->mlx, "textures/coin.xpm",
			&vars->img.img_h, &vars->img.img_w);
	if (!vars->img.colletibiles)
		return (destroy_image(vars, 4));
	return (0);
}
