/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:55:18 by akaterji          #+#    #+#             */
/*   Updated: 2024/07/06 11:42:43 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_checker_file(t_map *map)
{
	size_t	len;

	len = ft_strlen(map->filename);
	if (map->filename[len - 1] != 'r')
		ft_error_filename();
	if (map->filename[len - 2] != 'e')
		ft_error_filename();
	if (map->filename[len - 3] != 'b')
		ft_error_filename();
	if (map->filename[len - 4] != '.')
		ft_error_filename();
	if (!ft_strnstr(map->filename, ".ber", len))
		ft_error_filename();
}

static void	ft_checker_wall(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (map->game[0][x] == '1' && map->game[0][x])
		x++;
	if (map->game[0][x] != '\0')
		ft_error_wall(map);
	y = 1;
	while (y < map->y)
	{
		if (map->game[y][0] != '1' || map->game[y][map->x - 1] != '1')
			ft_error_wall(map);
		y++;
	}
	x = 0;
	while (map->game[map->y - 1][x] == '1' && map->game[map->y - 1][x] != '\0')
		x++;
	if (map->game[map->y - 1][x] != '\0')
		ft_error_wall(map);
}

static	void	ft_checker_params(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if (map->game[y][x] == 'C')
				map->c += 1;
			else if (map->game[y][x] == 'E')
				map->e += 1;
			else if (map->game[y][x] == 'P')
				map->p += 1;
			else if (map->game[y][x] == '0' || map->game[y][x] == '1')
				;
			else
				ft_error_map_elements(map);
			x++;
		}
		y++;
	}
	if (map->c < 1 || map->e > 1 || map->p != 1)
		ft_error_map_elements(map);
}

void	ft_checker_size(t_map *map)
{
	int	y;
	int	x;
	int	len;

	y = 0;
	x = 0;
	len = ft_strlen(map->game[y]);
	while (y < map->y)
	{
		x = ft_strlen(map->game[y]);
		if (len != x)
			ft_error_size(map);
		y++;
	}
	map->x = len;
}

void	ft_map_checker(t_map *map)
{
	ft_checker_file(map);
	ft_read_map(map);
	ft_checker_size(map);
	ft_checker_wall(map);
	ft_checker_params(map);
	ft_checker_valid_path(map);
}
