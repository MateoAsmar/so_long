/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:26:24 by masmar            #+#    #+#             */
/*   Updated: 2024/08/19 09:26:54 by masmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

// Checks if the game map is rectangular
static bool	is_rectangular(t_data *game)
{
	int		i;
	int		first_row_length;
	int		row_length;

	i = 1;
	first_row_length = ft_strlen(game->map[0]);
	while (i < game->height)
	{
		row_length = ft_strlen(game->map[i]);
		if (first_row_length != row_length)
			return (false);
		i++;
	}
	return (true);
}

// Checks whether the outer walls of the game map
// are properly enclose by walls(1)
static bool	wall_check(t_data *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < game->width)
	{
		if (game->map[0][x] != '1' || game->map[game->height - 1][x] != '1')
			return (false);
		x++;
	}
	while (y < game->height)
	{
		if (game->map[y][0] != '1' || game->map[y][game->width - 1] != '1')
			return (false);
		y++;
	}
	return (true);
}

// Checks the contents of a specific cellin the map
// to identify valid items or characters and counts them
bool	item_checker(t_data *game, int *cplayer, int x, int y)
{
	if (game->map[y][x] == 'C')
		return (game->tchicken++, true);
	else if (game->map[y][x] == 'E')
		return (game->texit++, true);
	else if (game->map[y][x] == 'P' || game->map[y][x] == 'L'
			|| game->map[y][x] == 'Y' || game->map[y][x] == 'I')
		return ((*cplayer)++, true);
	else if (game->map[y][x] == '1')
		return (true);
	else if (game->map[y][x] == '0')
		return (true);
	return (false);
}

// Checks the overall validity of the game map by ensuring it
// contains valid characters and correct quantities of key items
static int	overall_validity(t_data *game)
{
	int	cplayer;
	int	x;
	int	y;

	cplayer = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (!item_checker(game, &cplayer, x, y))
			{
				fd_putstr("Error\nInvalid character.\n", 2);
				return (destroy_exit(game), 0);
			}
			x++;
		}
		y++;
	}
	if (game->texit != 1 || game->tchicken == 0 || cplayer > 1)
		return (0);
	return (1);
}

// Checks the map for common errors
// and terminates the program if any are found
void	overall_errors(t_data *game)
{
	if (!is_rectangular(game))
	{
		fd_putstr("Error\nInvalid map format.\n", 2);
		return (destroy_exit(game), (void)0);
	}
	if (!wall_check(game))
	{
		fd_putstr("Error\nInvalid Walls.\n", 2);
		return (destroy_exit(game), (void)0);
	}
	if (overall_validity(game) != 1)
	{
		fd_putstr("Error\nInvalid map format.\n", 2);
		return (destroy_exit(game), (void)0);
	}
}
