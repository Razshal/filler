/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 18:18:15 by mfonteni          #+#    #+#             */
/*   Updated: 2018/02/14 15:11:04 by mfonteni         ###   ########.fr       */
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
/*
static void	whereami(t_fill *infos, t_coord pos)
{
	char c;
	static int i = 0;
	if (pos.y < infos->gridsize.y && pos.x < infos->gridsize.x && pos.y >= 0 && pos.x >= 0)
	{
		c = infos->grid[pos.y][pos.x];
		dprintf(FD, "loop n%d\n", i++);
		infos->grid[pos.y][pos.x] = 'A';
		ft_print_split_fd(infos->grid, FD);
	}
	else
		c = -1;
	if (c > -1)
		infos->grid[pos.y][pos.x] = c;
	usleep(1000);
}
*/
int		place_piece(t_fill *infos, t_coord place, int line, int row)
{
	int res;

	res = 0;
//	whereami(infos, place);
	if (!infos->currentpiece[line] && infos->overflow == 1)
	{
		infos->place.x = place.x;
		infos->place.y = place.y;
		infos->overflow = 0;
		return (1);
	}
	else if (((!infos->currentpiece[line] && infos->overflow != 1) ||
			!valid_placement(infos, place, line, row)) && !(infos->overflow = 0))
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
