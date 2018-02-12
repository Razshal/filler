/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 10:54:48 by mfonteni          #+#    #+#             */
/*   Updated: 2018/02/12 19:39:51 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_coord grid_search(t_fill *infos, char c)
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
	if (infos->playerinit.y == - 1)
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

t_coord	side_to_fill(t_fill *infos)
{
	t_coord	pos;

	pos.x = infos->playerinit.x < infos->enmyinit.x ? infos->gridsize.x - 1 : 0;
	pos.y = infos->gridsize.y / 2;
	
	if ((scan_row(infos, pos.x, ENMYCHAR) > infos->gridsize.x / 3)
		|| (scan_row(infos, pos.x, infos->player) && scan_row(infos,
		(pos.x == 0 ? infos->gridsize.x - 1 : 0), infos->player)))
//		|| (scan_row(infos, infos->playerinit.x, ENMYCHAR)))
	{
		pos.x = -1;
		pos.y = -1;
		return (pos);
	}
	if (scan_row(infos, pos.x, infos->player))
		return (infos->playerinit);
	else
	{
		pos.y = 0;
		while (infos->grid[pos.y] && infos->grid[pos.y][pos.x] != '.')
			pos.y++;
	}
	return (pos);
}
