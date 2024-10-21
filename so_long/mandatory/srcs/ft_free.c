/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:29:22 by akaterji          #+#    #+#             */
/*   Updated: 2024/07/06 12:36:24 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_free_rows(char **game, int i)
{
	while (i > 0)
		free(game[--i]);
	free(game);
	return (0);
}

void	ft_exit_free(t_map *map)
{
	if (map->game)
		free(map->game);
	if (map->cpy_game)
		free(map->cpy_game);
	if (map->file)
		free(map->file);
	if (map->line)
		free(map->line);
	exit(EXIT_FAILURE);
}
