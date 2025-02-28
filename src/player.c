/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:28:45 by masmar            #+#    #+#             */
/*   Updated: 2024/08/19 09:28:57 by masmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

// Checks if the given coordinates (x, y) contain a player or related
// entity and updates the player's position in the game structure
static bool	player(t_data *game, int x, int y)
{
	if (game->map[y][x] == 'P' || game->map[y][x] == 'L'
		|| game->map[y][x] == 'I' || game->map[y][x] == 'Y')
	{
		game->playery = y;
		game->playerx = x;
		return (true);
	}
	return (false);
}

// Finds and sets the player's position in the game structure
void	player_position(t_data *game)
{
	int	x;
	int	y;

	y = 0;
	if (game == NULL || game->map == NULL)
	{
		fd_putstr("Error\nInvalid Map\n", 2);
		destroy_exit(game);
	}
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (player(game, x, y))
				return ;
			x++;
		}
		y++;
	}
	fd_putstr("Error\nInvalid player\n", 2);
	destroy_exit(game);
}

// Displays the map and processes each item on the map
void	show_map(t_data *game)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			item_input(game, x, y);
			x++;
		}
		y++;
	}
}
