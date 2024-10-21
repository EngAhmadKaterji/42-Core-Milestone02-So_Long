/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_to_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:19:28 by akaterji          #+#    #+#             */
/*   Updated: 2024/07/05 09:52:07 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_file_to_image_player(t_map *map)
{
	int	img_pxl;

	img_pxl = IMG_PXL;
	map->img.player_right = mlx_xpm_file_to_image(map->mlx_ptr,
			"imgs/player/right.xpm", &img_pxl, &img_pxl);
	map->img.player_back = mlx_xpm_file_to_image(map->mlx_ptr,
			"imgs/player/back.xpm", &img_pxl, &img_pxl);
	map->img.player_left = mlx_xpm_file_to_image(map->mlx_ptr,
			"imgs/player/left.xpm", &img_pxl, &img_pxl);
	map->img.player_front = mlx_xpm_file_to_image(map->mlx_ptr,
			"imgs/player/front.xpm", &img_pxl, &img_pxl);
}

void	ft_file_to_image(t_map *map)
{
	int	img_pxl;

	img_pxl = IMG_PXL;
	map->img.floor = mlx_xpm_file_to_image(map->mlx_ptr,
			"imgs/floor.xpm", &img_pxl, &img_pxl);
	map->img.wall = mlx_xpm_file_to_image(map->mlx_ptr,
			"imgs/wall.xpm", &img_pxl, &img_pxl);
	map->img.exit = mlx_xpm_file_to_image(map->mlx_ptr,
			"imgs/open-exit.xpm", &img_pxl, &img_pxl);
	map->img.collectible = mlx_xpm_file_to_image(map->mlx_ptr,
			"imgs/coin-bag.xpm", &img_pxl, &img_pxl);
	ft_file_to_image_player(map);
}
