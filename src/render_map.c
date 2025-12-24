/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msancar <msancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:15:51 by msancar           #+#    #+#             */
/*   Updated: 2025/12/17 13:40:55 by msancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

void	render_map(t_vars *vars)
{
	int		y;
	int		x;
	char	c;
	void	*img;

	y = -1;
	while (++y < vars->map->m_height)
	{
		x = -1;
		while (++x < vars->map->m_width)
		{
			c = vars->map->map[y][x];
			img = vars->img.floor;
			if (c == '1')
				img = vars->img.wall;
			mlx_put_image_to_window(vars->mlx, vars->win, img, x * 48, y * 48);
			if (c == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->img.exit, x * 48, y * 48);
			else if (c == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->img.colletibiles, x * 48, y * 48);
		}
	}
}
