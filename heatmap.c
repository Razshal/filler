/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 18:38:10 by mfonteni          #+#    #+#             */
/*   Updated: 2018/02/15 19:43:03 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	ennemy_border(t_fill *infos, t_coord pos)
{
	if (infos->grid[pos.y][pos.x] != NOTHING)
		return (1);
	if (infos->grid[pos.y + 1][pos.x] <= ENNEMY)
		return (infos->grid[pos.y][pos.x] = 1);
	if (infos->grid[pos.y - 1][pos.x] <= ENNEMY)
		return (infos->grid[pos.y][pos.x] = 1);
	if (infos->grid[pos.y][pos.x + 1] <= ENNEMY)
		return (infos->grid[pos.y][pos.x] = 1);
	if (infos->grid[pos.y][pos.x - 1] <= ENNEMY)
		return (infos->grid[pos.y][pos.x] = 1);
	return (0);
}

static void	heating_grid(t_fill *infos, t_coord pos)
{
	int min;

	min = 2147483647;
	if (infos->grid[pos.y][pos.x] != NOTHING)
		return ;
	if (infos->grid[pos.y + 1][pos.x] != NOTHING
			&& infos->grid[pos.y + 1][pos.x] < min)
		min = infos->grid[pos.y + 1][pos.x];
	if (infos->grid[pos.y - 1][pos.x] != NOTHING
			&& infos->grid[pos.y - 1][pos.x] < min)
		min = infos->grid[pos.y - 1][pos.x];
	if (infos->grid[pos.y][pos.x + 1] != NOTHING
			&& infos->grid[pos.y][pos.x + 1] < min)
		min = infos->grid[pos.y][pos.x + 1];
	if (infos->grid[pos.y][pos.x - 1] != NOTHING
			&& infos->grid[pos.y][pos.x - 1] < min)
		min = infos->grid[pos.y][pos.x - 1];
	if (min != 2147483647)
		infos->grid[pos.y][pos.x] = min + 1;
}

int		heatmap_init(t_fill *infos)
{
	t_coord	pos;
	int		emptycases;

	pos.y = 0;
	emptycases = 0;
	while (pos.y++ < infos->gridsize.y)
	{
		pos.x = 0;
		while (pos.x++ < infos->gridsize.x)
		{
			if (infos->grid[pos.y][pos.x] == NOTHING)
				emptycases++;
			if (!ennemy_border(infos, pos))
				heating_grid(infos, pos);
		}
	}
	return (emptycases == 0 ? 1 : heatmap_init(infos));
}
