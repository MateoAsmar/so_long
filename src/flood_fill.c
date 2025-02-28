/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:27:15 by masmar            #+#    #+#             */
/*   Updated: 2024/08/23 16:11:19 by masmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

// Initialized a 2D array (called stepped) to keep track
// of the positions that have been checked or visited in the game
static int	**init_stepped(t_data *game)
{
	int	**stepped;
	int	y;

	y = 0;
	stepped = ft_calloc(game->height, sizeof(int *));
	if (!stepped)
		return (NULL);
	while (y < game->height)
	{
		stepped[y] = ft_calloc(game->width, sizeof(int));
		if (!stepped[y])
		{
			destroy_stepped(stepped, game);
			fd_putstr("Error\nInvalid allocation", 2);
		}
		y++;
	}
	return (stepped);
}

// Checks if there are any unreachable exit points
// or collectiles in the game map after a flood fill operation
static void	check_chicken(t_data *game, int **stepped)
{
	int		y;
	int		x;
	bool	error_found;

	y = 0;
	error_found = false;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (!stepped[y][x] && (game->map[y][x] == 'E'
				|| game->map[y][x] == 'C'))
			{
				error_found = true;
				destroy_stepped(stepped, game);
				fd_putstr("Error\nExpired Chicken\n", 2);
				destroy_exit(game);
			}
			x++;
		}
		y++;
	}
	if (error_found)
		exit(1);
}

// Performs a flood fill algorithm to mark
// accessible areas on the map starting from the players position
static void	flood_fill(t_data *game, int **stepped, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->width || y >= game->height)
		return ;
	if (stepped[y][x] || game->map[y][x] == '1')
		return ;
	stepped[y][x] = 1;
	flood_fill(game, stepped, x - 1, y);
	flood_fill(game, stepped, x + 1, y);
	flood_fill(game, stepped, x, y - 1);
	flood_fill(game, stepped, x, y + 1);
}

// Checks whether all important areas (E and C) on the map
// are accessible from the player's starting position
void	is_accessible(t_data *game)
{
	int	**stepped;

	stepped = init_stepped(game);
	if (!stepped)
	{
		fd_putstr("Error\nFailed to initialize step tracking\n", 2);
		destroy_exit(game);
	}
	flood_fill(game, stepped, game->playerx, game->playery);
	check_chicken(game, stepped);
	destroy_stepped(stepped, game);
}
