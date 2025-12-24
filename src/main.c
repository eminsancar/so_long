/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msancar <msancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:11:34 by msancar           #+#    #+#             */
/*   Updated: 2025/12/23 19:31:30 by msancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "mlx.h"
#include "so_long.h"
#include <stdlib.h>

void	exit_and_free(char *message, t_vars *vars)
{
	int	i;

	if (vars)
	{
		if (vars->map)
		{
			if (vars->map->map)
			{
				i = 0;
				while (vars->map->map[i])
				{
					free(vars->map->map[i]);
					i++;
				}
				free(vars->map->map);
			}
			free(vars->map);
		}
		free(vars);
	}
	if (message)
		ft_printf("%s\n", message);
	exit(1);
}

void	move(int keycode, t_vars *vars)
{
	if ((keycode == 119 || keycode == 65362)
		&& vars->map->map[vars->p_height - 1][vars->p_width] != '1')
		vars->p_height--;
	else if ((keycode == 97 || keycode == 65361)
		&& vars->map->map[vars->p_height][vars->p_width - 1] != '1')
		vars->p_width--;
	else if ((keycode == 100 || keycode == 65363)
		&& vars->map->map[vars->p_height][vars->p_width + 1] != '1')
		vars->p_width++;
	else if ((keycode == 115 || keycode == 65364)
		&& vars->map->map[vars->p_height + 1][vars->p_width] != '1')
		vars->p_height++;
	else
		return ;
	ft_printf("Moves: %d\n", ++vars->movement);
	if (vars->map->map[vars->p_height][vars->p_width] == 'C')
	{
		vars->c_c--;
		vars->map->map[vars->p_height][vars->p_width] = '0';
	}
	if (vars->map->map[vars->p_height][vars->p_width] == 'E' && vars->c_c == 0)
	{
		ft_printf("Sancar Win!\n");
		close_win(vars);
	}
}

int	key_press(int key, t_vars *vars)
{
	if (key == 65307)
		close_win(vars);
	if (key == 119 || key == 115 || key == 97 || key == 100 || key == 65362
		|| key == 65364 || key == 65361 || key == 65363)
		move(key, vars);
	return (0);
}

int	close_win(t_vars *vars)
{
	if (vars)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_image(vars->mlx, vars->img.wall);
		mlx_destroy_image(vars->mlx, vars->img.player);
		mlx_destroy_image(vars->mlx, vars->img.floor);
		mlx_destroy_image(vars->mlx, vars->img.exit);
		mlx_destroy_image(vars->mlx, vars->img.colletibiles);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	exit_and_free("EXIT!", vars);
	exit(1);
}

int	main(int ac, char **av)
{
	t_vars	*vars;

	if (ac != 2)
		exit_and_free("Check number of arguments!", NULL);
	check_av(av[1]);
	vars_init(av[1], &vars);
	check_map_acces(vars);
	init_mlx(vars);
	mlx_hook(vars->win, 2, 1L << 0, key_press, vars);
	mlx_hook(vars->win, 17, 0, close_win, vars);
	mlx_loop_hook(vars->mlx, new_mlx, vars);
	mlx_loop(vars->mlx);
}
