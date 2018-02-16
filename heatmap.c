/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 18:38:10 by mfonteni          #+#    #+#             */
/*   Updated: 2018/02/16 12:57:00 by mfonteni         ###   ########.fr       */
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

static void		heating_grid(t_fill *infos, t_coord pos)
{
	int min;

	min = 2147483647;
	if (infos->grid[pos.y][pos.x] != NOTHING)
		return ;
	if (infos->grid[pos.y + 1][pos.x] != NOTHING
			&& infos->grid[pos.y + 1][pos.x] < min
			&& infos->grid[pos.y + 1][pos.x] > 0)
		min = infos->grid[pos.y + 1][pos.x];
	if (infos->grid[pos.y - 1][pos.x] != NOTHING
			&& infos->grid[pos.y - 1][pos.x] < min
			&& infos->grid[pos.y - 1][pos.x] > 0)
		min = infos->grid[pos.y - 1][pos.x];
	if (infos->grid[pos.y][pos.x + 1] != NOTHING
			&& infos->grid[pos.y][pos.x + 1] < min
			&& infos->grid[pos.y][pos.x + 1] > 0)
		min = infos->grid[pos.y][pos.x + 1];
	if (infos->grid[pos.y][pos.x - 1] != NOTHING
			&& infos->grid[pos.y][pos.x - 1] < min
			&& infos->grid[pos.y][pos.x - 1] > 0)
		min = infos->grid[pos.y][pos.x - 1];
	if (min != 2147483647)
		infos->grid[pos.y][pos.x] = min + 1;
}

int			heatmap_init(t_fill *infos)
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

static t_coord	heatmap_get_best_point(t_fill *infos, int decal)
{
	t_coord	pos;
	t_coord	final_pos;
	int		bestvalue;

	bestvalue = 2147483647;
	pos.x = 0;
	pos.y = 0;
	while (pos.y++ < infos->gridsize.y)
	{
		while (pos.x++ < infos->gridsize.x)
		{
			if (infos->grid[pos.y][pos.x] > 0
					&& infos->grid[pos.y][pos.x] < bestvalue && decal-- <= 0)
			{
				final_pos = pos;
				bestvalue = infos->grid[pos.y][pos.x];
			}
		}
	}
	return (final_pos);
}

int		heatmap_search(t_fill *infos)
{
	int		decal;
	int		res;
	t_coord best_pos;
	t_coord	tries;
	t_coord	convert;

	decal = 0;
	res = 0;
	while (!res && decal++ < infos->gridsize.y * infos->gridsize.x)
	{
		tries.y = 0;
		best_pos = heatmap_get_best_point(infos, decal);
		while (!res && tries.y++ <= infos->piecesize.y)
		{
			tries.x = 0;
			while (!res && tries.x++ <= infos->piecesize.x)
			{
				convert.x = best_pos.x - tries.x;
				convert.y = best_pos.y - tries.y;
				res = place_piece(infos, convert, 0, 0);
			}
		}
	}
	if (res)
		ft_printf("%d %d\n", convert.y, convert.x);
	return (res);
}
