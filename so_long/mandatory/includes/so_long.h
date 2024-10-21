/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:03:09 by akaterji          #+#    #+#             */
/*   Updated: 2024/07/06 09:58:22 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../../libft/libft.h"
# include "../../mlx/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define UP      65362
# define DOWN    65364
# define LEFT    65361
# define RIGHT   65363
# define ESC     65307
# define IMG_PXL 	30
# define WND_NAME "so_long"

typedef struct s_player
{
	int	y;
	int	x;
}	t_player;

typedef struct s_img
{
	void	*floor;
	void	*collectible;
	void	*wall;
	void	*player_left;
	void	*player_right;
	void	*player_front;
	void	*player_back;
	void	*exit;
}	t_img;

typedef struct s_map
{
	t_player	player;
	t_img		img;
	int			fd;
	char		*line;
	char		*file;
	char		**game;
	char		**cpy_game;
	char		*filename;
	int			y;
	int			x;
	int			e;
	int			c;
	int			c_check;
	int			e_check;
	int			p;
	int			exit;
	int			moves;
	void		*mlx_ptr;
	void		*win_ptr;
}	t_map;

//init a map
void	ft_map_init(t_map *map, char *filename);

// checckers for the map
void	ft_map_checker(t_map *map);
void	ft_checker_size(t_map *map);
void	ft_checker_file(t_map *map);
void	ft_checker_valid_path(t_map *map);
void	ft_move_to_paths(int x, int y, t_map *map);

//get position of a player
void	ft_put_player(t_map *map);
//read a map
void	ft_read_map(t_map *map);

//show up the game
void	ft_map_printer(t_map *map);
void	ft_file_to_image(t_map *map);
void	ft_file_to_image_player(t_map *map);

//reading the moves
int		key_hook(int keycode, t_map *map);
void	move_up(t_map *map);
void	move_down(t_map *map);
void	move_left(t_map *map);
void	move_right(t_map *map);

//error handling
int		ft_free_rows(char **map, int i);
void	ft_exit_free(t_map *map);
void	ft_error_map_elements(t_map *map);
void	ft_error_wall(t_map *map);
void	ft_error_size(t_map *map);
void	ft_error_openfile(void);
void	ft_error_filename(void);

// destroy map
int		on_destroy(t_map *map);
void	ft_win(t_map *map);

//print
void	ft_print_movements(t_map *map);
#endif