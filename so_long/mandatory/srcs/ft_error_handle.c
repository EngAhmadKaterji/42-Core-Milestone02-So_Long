/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:08:04 by akaterji          #+#    #+#             */
/*   Updated: 2024/07/05 14:55:53 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_error_filename(void)
{
	ft_putstr_fd("Filename error", 2);
	exit(EXIT_FAILURE);
}

void	ft_error_openfile(void)
{
	ft_putstr_fd("Failed open\n", 2);
	exit(EXIT_FAILURE);
}

void	ft_error_size(t_map *map)
{
	ft_putstr_fd("Wrong Size Map\n", 2);
	ft_free_rows(map->game, map->y);
	ft_free_rows(map->cpy_game, map->y);
	exit(EXIT_FAILURE);
}

void	ft_error_wall(t_map *map)
{
	ft_putstr_fd("Wrong Walls\n", 2);
	ft_free_rows(map->game, map->y);
	ft_free_rows(map->cpy_game, map->y);
	exit(EXIT_FAILURE);
}

void	ft_error_map_elements(t_map *map)
{
	ft_putstr_fd("Failed elements", 2);
	ft_free_rows(map->game, map->y);
	ft_free_rows(map->cpy_game, map->y);
	exit(EXIT_FAILURE);
}
