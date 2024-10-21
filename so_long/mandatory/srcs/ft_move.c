/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:48:59 by akaterji          #+#    #+#             */
/*   Updated: 2024/07/05 14:51:18 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static	void	resume_move(t_map *map, int x, int y, int dir)
{
	if (dir == UP)
		y -= 1;
	if (dir == DOWN)
		y += 1;
	if (dir == LEFT)
		x -= 1;
	if (dir == RIGHT)
		x += 1;
	if (map->game[y][x] == 'E' && map->c == 0)
		return (ft_win(map));
	if (map->game[y][x] == 'C')
	{
		map->game[y][x] = '0';
		map->c--;
	}
}

void	move_up(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y;
	if (y > 0 && map->game[y - 1][x] != '1')
	{
		resume_move(map, x, y, UP);
		if (map->game[y - 1][x] == 'E' && (map->c != 0))
			return ;
		map->moves++;
		mlx_put_image_to_window(map->mlx_ptr,
			map->win_ptr, map->img.floor, x * IMG_PXL, y * IMG_PXL);
		map->game[y][x] = '0';
		y--;
		ft_print_movements(map);
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->img.floor, x * IMG_PXL, y * IMG_PXL);
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->img.player_back, x * IMG_PXL, y * IMG_PXL);
		map->game[y][x] = 'P';
		map->player.x = x;
	}
}

void	move_down(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y;
	if (y < map->y && map->game[y + 1][x] != '1')
	{
		resume_move(map, x, y, DOWN);
		if (map->game[y + 1][x] == 'E' && (map->c != 0))
			return ;
		map->moves++;
		mlx_put_image_to_window(map->mlx_ptr,
			map->win_ptr, map->img.floor, x * IMG_PXL, y * IMG_PXL);
		map->game[y][x] = '0';
		y++;
		ft_print_movements(map);
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->img.floor, x * IMG_PXL, y * IMG_PXL);
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->img.player_front, x * IMG_PXL, y * IMG_PXL);
		map->game[y][x] = 'P';
		map->player.y = y;
	}
}

void	move_left(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y;
	if (x > 0 && map->game[y][x - 1] != '1')
	{
		resume_move(map, x, y, LEFT);
		if (map->game[y][x - 1] == 'E' && (map->c != 0))
			return ;
		map->moves++;
		mlx_put_image_to_window(map->mlx_ptr,
			map->win_ptr, map->img.floor, x * IMG_PXL, y * IMG_PXL);
		map->game[y][x] = '0';
		x--;
		ft_print_movements(map);
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->img.floor, x * IMG_PXL, y * IMG_PXL);
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->img.player_left, x * IMG_PXL, y * IMG_PXL);
		map->game[y][x] = 'P';
		map->player.y = y;
	}
}

void	move_right(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y;
	if (x < map->x && map->game[y][x + 1] != '1')
	{
		resume_move(map, x, y, RIGHT);
		if (map->game[y][x + 1] == 'E' && (map->c != 0))
			return ;
		map->moves++;
		mlx_put_image_to_window(map->mlx_ptr,
			map->win_ptr, map->img.floor, x * IMG_PXL, y * IMG_PXL);
		map->game[y][x] = '0';
		x++;
		ft_print_movements(map);
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->img.floor, x * IMG_PXL, y * IMG_PXL);
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->img.player_right, x * IMG_PXL, y * IMG_PXL);
		map->game[y][x] = 'P';
		map->player.x = x;
	}
}
