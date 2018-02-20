/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 18:38:10 by mfonteni          #+#    #+#             */
/*   Updated: 2018/02/20 13:20:18 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		test_case(t_fill *infos, int line, int row, int min)
{
	t_coord pos;

	pos.y = line;
	pos.x = row;
	if (!is_on_grid(infos, pos.y, pos.x))
		return (min);
	if (infos->heatmap[pos.y][pos.x] == ENNEMYLASTPOS)
		return (0);
	if (infos->heatmap[pos.y][pos.x] == ENNEMY)
		return (infos->gridsize.y < 20 ? 1 :
				(infos->gridsize.x + infos->gridsize.y) / 12);
	else if (infos->heatmap[pos.y][pos.x] != NOTHING
			&& infos->heatmap[pos.y][pos.x] < min
			&& infos->heatmap[pos.y][pos.x] > 0)
		return (infos->heatmap[pos.y][pos.x]);
	return (min);
}

static int		heating_grid(t_fill *infos, t_coord pos)
{
	int min;

	min = 2147483647;
	if (infos->heatmap[pos.y][pos.x] != NOTHING
		&& infos->heatmap[pos.y][pos.x] != PLAYER)
		return (infos->heatmap[pos.y][pos.x]);
	min = test_case(infos, pos.y + 1, pos.x, min);
	min = test_case(infos, pos.y - 1, pos.x, min);
	min = test_case(infos, pos.y, pos.x + 1, min);
	min = test_case(infos, pos.y, pos.x - 1, min);
	if (min != 2147483647 && min >= 0)
		return (min + 1);
	return (infos->heatmap[pos.y][pos.x]);
}

void			heatmap_fill(t_fill *infos)
{
	t_coord	pos;
	int		emptycases;

	pos.y = -1;
	emptycases = 0;
	while (++pos.y < infos->gridsize.y)
	{
		pos.x = -1;
		while (++pos.x < infos->gridsize.x)
		{
			if (infos->heatmap[pos.y][pos.x] == NOTHING)
				emptycases++;
			infos->heatmap[pos.y][pos.x] = heating_grid(infos, pos);
		}
	}
	if (emptycases)
		heatmap_fill(infos);
}

static int	heatmap_get_best_point_o(t_fill *infos, int target)
{
	t_coord	pos;

	pos.y = -1;
	if (!heatmap_grid_search(infos, target) && target > 1)
		return (0);
	while (++pos.y < infos->gridsize.y)
	{
		pos.x = -1;
		while (++pos.x < infos->gridsize.x)
		{
			if (infos->heatmap[pos.y][pos.x] == target
					&& place_and_decal(infos, pos))
				return (ft_printf("%d %d\n",
							infos->place.y, infos->place.x));
		}
	}
	return (heatmap_get_best_point_o(infos, target + 1));
}

static int	heatmap_get_best_point_x(t_fill *infos, int target)
{
	t_coord	pos;

	pos.y = infos->gridsize.y - 1;
	if (!heatmap_grid_search(infos, target) && target > 1)
		return (0);
	while (pos.y >= 0)
	{
		pos.x = infos->gridsize.x - 1;
		while (pos.x >= 0)
		{
			if (infos->heatmap[pos.y][pos.x] == target
					&& place_and_decal(infos, pos))
				return (ft_printf("%d %d\n",
							infos->place.y, infos->place.x));
			pos.x--;
		}
		pos.y--;
	}
	return (heatmap_get_best_point_x(infos, target + 1));
}

int				heatmap_search(t_fill *infos)
{
	if (!heatmap_init(infos))
		return (0);
	heatmap_fill(infos);
	if (infos->player == 'X' && infos->gridsize.y > 20)
		return (heatmap_get_best_point_x(infos, 1));
	else
		return (heatmap_get_best_point_o(infos, 1));

}
