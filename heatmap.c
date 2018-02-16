/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 18:38:10 by mfonteni          #+#    #+#             */
/*   Updated: 2018/02/16 19:42:10 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		test_case(t_fill *infos, int line, int row, int min)
{
	t_coord pos;

	pos.y = line;
	pos.x = row;
	if (is_on_grid(infos, pos.y, pos.x)
			&& infos->grid[pos.y][pos.x] <= ENNEMY)
		return (infos->grid[pos.y][pos.x] = 1);
	else if (is_on_grid(infos, pos.y, pos.x)
			&& infos->heatmap[pos.y][pos.x] != NOTHING
			&& infos->heatmap[pos.y][pos.x] < min
			&& infos->heatmap[pos.y][pos.x] > 0)
		return (infos->grid[pos.y][pos.x]);
	return (min);
}

static void		heating_grid(t_fill *infos, t_coord pos)
{
	int min;

	min = 2147483647;
	if (infos->grid[pos.y][pos.x] != NOTHING)
		return ;
	min = test_case(infos, pos.y + 1, pos.x, min);
	min = test_case(infos, pos.y - 1, pos.x, min);
	min = test_case(infos, pos.y, pos.x + 1, min);
	min = test_case(infos, pos.y, pos.x - 1, min);
	if (min != 2147483647)
		infos->grid[pos.y][pos.x] = min + 1;
}

int				heatmap_fill(t_fill *infos)
{
	t_coord	pos;
	int		emptycases;

	pos.y = 0;
	emptycases = 0;
	if (!infos->heatmap && !create_array(infos))
		return (0);
	while (pos.y < infos->gridsize.y)
	{
		pos.x = 0;
		while (pos.x < infos->gridsize.x)
		{
			if (infos->heatmap[pos.y][pos.x] == NOTHING)
				emptycases++;
			heating_grid(infos, pos);
			pos.x++;
		}
		pos.y++;
	}
	if (!emptycases)
		return (1);
	return (0);
}

static t_coord	heatmap_get_best_point(t_fill *infos, int decal)
{
	t_coord	pos;
	t_coord	final_pos;
	int		bestvalue;

	bestvalue = 2147483647;
	pos.y = -1;
	while (++pos.y < infos->gridsize.y)
	{
		pos.x = -1;
		while (pos.x++ < infos->gridsize.x)
		{
			if (is_on_grid(infos, pos.y, pos.x)
					&& infos->grid[pos.y][pos.x] > 0
					&& infos->grid[pos.y][pos.x] < bestvalue && decal-- == 0)
			{
				final_pos = pos;
				bestvalue = infos->grid[pos.y][pos.x];
			}
		}
	}
	dprintf(FD, "y%d x%d bastvalue%d decal %d\n", pos.y, pos.x, bestvalue, decal);
	return (final_pos);
}

int				heatmap_search(t_fill *infos)
{
	int		decal;
	int		res;
	t_coord best_pos;
	t_coord	tries;
	t_coord	convert;

	decal = 0;
	res = 0;
	while (!res && decal < infos->gridsize.y * infos->gridsize.x)
	{
		tries.y = -1;
		best_pos = heatmap_get_best_point(infos, decal++);
		dprintf(FD, "decal%d\n", decal);
		while (!res && ++tries.y <= infos->piecesize.y)
		{
			tries.x = -1;
			while (!res && ++tries.x <= infos->piecesize.x)
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
