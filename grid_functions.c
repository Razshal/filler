/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 10:54:48 by mfonteni          #+#    #+#             */
/*   Updated: 2018/02/15 13:35:48 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_coord	grid_search(t_fill *infos, char c)
{
	int		line;
	int		row;
	t_coord	place;

	line = -1;
	while (infos->grid[++line])
	{
		row = -1;
		while (infos->grid[line][++row])
		{
			if (infos->grid[line][row] == c)
			{
				place.y = line;
				place.x = row;
				return (place);
			}
		}
	}
	place.x = -1;
	return (place);
}

t_coord	enmypos(t_fill *infos)
{
	t_coord enmy;

	enmy = grid_search(infos, (infos->player == 'X' ? 'o' : 'x'));
	if (enmy.x < 0)
		enmy = grid_search(infos, (infos->player == 'X' ? 'O' : 'X'));
	return (enmy);
}

void	initpos(t_fill *infos)
{
	if (infos->enmyinit.y == -1)
		infos->enmyinit = grid_search(infos,
				(infos->player == 'X' ? 'O' : 'X'));
	if (infos->playerinit.y == -1)
		infos->playerinit = grid_search(infos, infos->player);
}

int		scan_row(t_fill *infos, int x, char c)
{
	int y;
	int count;

	y = 0;
	count = 0;
	while (y < infos->gridsize.y)
	{
		if (infos->grid[y++][x] == c)
			count++;
	}
	return (count);
}
