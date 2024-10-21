/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:11:41 by akaterji          #+#    #+#             */
/*   Updated: 2024/07/25 10:57:58 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_win(t_map *map)
{
	map->exit = 1;
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	mlx_string_put(map->mlx_ptr, map->win_ptr,
		map->x / 2 * IMG_PXL, map->y / 2 * IMG_PXL, 0xFFFA9E, "YOU WON");
	write(1, "\n", 1);
	write(1, "\x1b[32;01m", 9);
	write(1, "🏆🏆YOU WON!!🏆🏆\n", 27);
	write(1, "\x1b[0m", 5);
}

void	ft_destroy_images(t_map *map)
{
	mlx_destroy_image(map->mlx_ptr, map->img.collectible);
	mlx_destroy_image(map->mlx_ptr, map->img.exit);
	mlx_destroy_image(map->mlx_ptr, map->img.floor);
	mlx_destroy_image(map->mlx_ptr, map->img.player_back);
	mlx_destroy_image(map->mlx_ptr, map->img.player_front);
	mlx_destroy_image(map->mlx_ptr, map->img.player_left);
	mlx_destroy_image(map->mlx_ptr, map->img.player_right);
	mlx_destroy_image(map->mlx_ptr, map->img.wall);
}

int	on_destroy(t_map *map)
{
	ft_destroy_images(map);
	ft_free_rows(map->game, map->y);
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	mlx_destroy_display(map->mlx_ptr);
	free(map->mlx_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_map_init(t_map *map, char *filename)
{
	map->filename = filename;
	map->moves = 0;
	map->e = 0;
	map->c = 0;
	map->p = 0;
	map->y = 0;
	map->x = 0;
	map->player.y = 0;
	map->player.x = 0;
	map->exit = 0;
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc == 2)
	{
		ft_map_init(&map, argv[1]);
		ft_map_checker(&map);
		map.mlx_ptr = mlx_init();
		map.win_ptr = mlx_new_window(map.mlx_ptr, map.x * IMG_PXL,
				map.y * IMG_PXL, WND_NAME);
		ft_file_to_image(&map);
		ft_map_printer(&map);
		mlx_hook(map.win_ptr, DestroyNotify, StructureNotifyMask,
			on_destroy, &map);
		mlx_key_hook(map.win_ptr, key_hook, &map);
		mlx_loop(map.mlx_ptr);
	}
	exit(EXIT_FAILURE);
}
