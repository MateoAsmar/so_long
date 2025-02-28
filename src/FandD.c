/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fandD.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:26:07 by masmar            #+#    #+#             */
/*   Updated: 2024/08/19 09:26:11 by masmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

// Frees the memory allocated for the game map
void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

// Cleans up and frees all resources
// associated with the game before enxiting the program
int	destroy_exit(t_data *game)
{
	int	i;

	i = 0;
	free_map(game->map);
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
	if (game->chicken)
		mlx_destroy_image(game->mlx, game->chicken);
	if (game->floor)
		mlx_destroy_image(game->mlx, game->floor);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(0);
}

// Frees the memory allocated for a 2D array of integers
void	destroy_stepped(int **stepped, t_data *game)
{
	int	y;

	y = 0;
	while (y < game->height)
		free(stepped[y++]);
	free(stepped);
}
