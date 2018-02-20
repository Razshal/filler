/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 18:18:15 by mfonteni          #+#    #+#             */
/*   Updated: 2018/02/20 17:30:01 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	valid_placement(t_fill *infos, t_coord place, int line, int row)
{
	if (infos->currentpiece[line][row] == '*')
	{
		if (line > infos->piecesize.y
				|| row > infos->piecesize.x
				|| line + place.y < 0
				|| row + place.x < 0
				|| line + place.y > infos->gridsize.y
				|| row + place.x > infos->gridsize.x)
			return (0);
		if (!infos->grid[line + place.y])
			return (0);
		if (infos->grid[line + place.y][row + place.x] != '.'
				&& infos->grid[line + place.y][row + place.x] != infos->player)
			return (0);
	}
	return (1);
}

int			place_piece(t_fill *infos, t_coord place, int line, int row)
{
	int res;

	res = 0;
	if (!infos->currentpiece[line] && infos->overflow == 1)
	{
		infos->place.x = place.x;
		infos->place.y = place.y;
		infos->overflow = 0;
		return (1);
	}
	else if (((!infos->currentpiece[line] && infos->overflow != 1) ||
			!valid_placement(infos, place, line, row))
			&& !(infos->overflow = 0))
		return (0);
	if (infos->currentpiece[line][row] == '*' &&
			infos->grid[line + place.y][row + place.x] == infos->player)
		infos->overflow++;
	if (infos->overflow > 1 && !(infos->overflow = 0))
		return (0);
	if (row < infos->piecesize.x)
		res = place_piece(infos, place, line, ++row);
	else if (line < infos->piecesize.y)
		res = place_piece(infos, place, ++line, 0);
	infos->overflow = 0;
	return (res);
}

int			place_and_decal(t_fill *infos, t_coord pos)
{
	t_coord	tries;
	t_coord	convert;
	int		res;

	tries.y = -1;
	res = 0;
	while (!res && ++tries.y <= infos->piecesize.y)
	{
		tries.x = -1;
		while (!res && ++tries.x <= infos->piecesize.x)
		{
			convert.x = pos.x - tries.x;
			convert.y = pos.y - tries.y;
			if ((res = place_piece(infos, convert, 0, 0)))
			{
				infos->place = convert;
				return (1);
			}
		}
	}
	return (0);
}
