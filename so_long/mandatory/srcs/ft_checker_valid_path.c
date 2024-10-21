/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_valid_path.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:12:11 by akaterji          #+#    #+#             */
/*   Updated: 2024/08/01 17:33:31 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_move_to_paths(int x, int y, t_map *map)
{
	char	type;

	type = map->cpy_game[y][x];
	if (type == 'C')
	{
		map->c_check -= 1;
		map->cpy_game[y][x] = '1';
	}
	else if (type == 'E')
	{
		map->e_check -= 1;
		map->cpy_game[y][x] = '1';
	}
	else if (type == '0' || type == 'P')
		map->cpy_game[y][x] = '1';
	else
		return ;
	ft_move_to_paths(x + 1, y, map);
	ft_move_to_paths(x - 1, y, map);
	ft_move_to_paths(x, y + 1, map);
	ft_move_to_paths(x, y - 1, map);
}

void	ft_checker_valid_path(t_map *map)
{
	map->c_check = map->c;
	map->e_check = map->e;
	ft_put_player(map);
	ft_move_to_paths(map->player.x, map->player.y, map);
	if (map->c_check != 0 || map->e_check >= map->e)
	{
		ft_putstr_fd("No valid path\n", 2);
		ft_free_rows(map->game, map->y);
		ft_free_rows(map->cpy_game, map->y);
		exit(EXIT_FAILURE);
	}
	ft_free_rows(map->cpy_game, map->y);
}
