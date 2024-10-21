/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_printer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:53:36 by akaterji          #+#    #+#             */
/*   Updated: 2024/07/06 13:44:01 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_map_type(t_map *map, int x, int y)
{
	int	type;

	type = map->game[y / IMG_PXL][x / IMG_PXL];
	if (type == '0')
		mlx_put_image_to_window(map->mlx_ptr,
			map->win_ptr, map->img.floor, x, y);
	else if (type == 'C')
		mlx_put_image_to_window(map->mlx_ptr,
			map->win_ptr, map->img.collectible, x, y);
	else if (type == 'P')
		mlx_put_image_to_window(map->mlx_ptr,
			map->win_ptr, map->img.player_front, x, y);
	else if (type == 'E')
		mlx_put_image_to_window(map->mlx_ptr,
			map->win_ptr, map->img.exit, x, y);
	else if (type == '1')
		mlx_put_image_to_window(map->mlx_ptr,
			map->win_ptr, map->img.wall, x, y);
}

void	ft_map_printer(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			ft_map_type(map, x * IMG_PXL, y * IMG_PXL);
			x++;
		}
		y++;
	}
}

void	ft_print_movements(t_map *map)
{
	char	*move;

	move = ft_itoa(map->moves);
	ft_putstr_fd("\r", 1);
	ft_putstr_fd("\x1b[33;01m", 1);
	ft_putstr_fd(move, 1);
	ft_putstr_fd("\x1b[0m", 1);
	ft_putstr_fd(" movements", 1);
	free(move);
}
