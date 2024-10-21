/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:17:34 by akaterji          #+#    #+#             */
/*   Updated: 2024/07/04 18:02:25 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_put_player(t_map *map)
{
	map->player.x = 0;
	map->player.y = 0;
	while (map->player.y < map->y)
	{
		while (map->player.x < map->x)
		{
			if (map->game[map->player.y][map->player.x] == 'P')
				break ;
			map->player.x++;
		}
		if (map->game[map->player.y][map->player.x] == 'P')
			break ;
		map->player.x = 0;
		map->player.y++;
	}
}
