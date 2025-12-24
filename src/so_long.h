/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msancar <msancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:16:41 by msancar           #+#    #+#             */
/*   Updated: 2025/12/23 16:46:44 by msancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 42

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	int		m_height;
	int		m_width;
	int		p_height;
	int		p_width;
}			t_map;

typedef struct s_img
{
	void	*wall;
	void	*colletibiles;
	void	*exit;
	void	*player;
	void	*floor;
	int		img_w;
	int		img_h;
}			t_img;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_map	*map;
	int		temp_c;
	int		temp_e;
	int		collectibles;
	int		m_width;
	int		p_height;
	int		p_width;
	int		movement;
	int		c_c;
	t_img	img;
}			t_vars;

int			close_win(t_vars *vars);
void		check_av(const char *map);
void		ft_error(char *av);
void		vars_init(const char *map, t_vars **vars);
void		exit_and_free(char *message, t_vars *vars);
void		m_scaling(t_vars **vars);
void		p_scaling(t_vars **vars);
int			index_counter(t_vars *vars, char c);
char		*get_next_line(int fd);
int			read_file_map(char *map);
char		**clone_map(t_vars *vars);
void		check_map_acces(t_vars *vars);
int			images(t_vars *vars);
int			key_press(int key, t_vars *vars);
void		render_map(t_vars *vars);
void		map_investigation(t_vars *vars);
void		check_row_rect_and_sides(t_vars *vars, int i, unsigned int width);
void		check_row_chars(t_vars *vars, int i);
int			check_middle_rows(t_vars *vars, unsigned int width);
void		check_player_exit_count(t_vars *vars);
void		check_bottom_wall(t_vars *vars, int last_i);
int			new_mlx(t_vars *vars);
void		init_mlx(t_vars *vars);

#endif
