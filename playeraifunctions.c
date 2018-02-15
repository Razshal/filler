/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playeraifunctions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 12:04:16 by mfonteni          #+#    #+#             */
/*   Updated: 2018/02/15 14:46:00 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		right_side(t_fill *infos, t_coord enmy, int cur)
{
	int		res;
	t_coord	pos;

	res = 0;
	pos.x = enmy.x + cur;
	pos.y = enmy.y - cur;
	while (!(res = place_piece(infos, pos, 0, 0)) && pos.x > enmy.x - cur)
		pos.x--;
	pos.x = enmy.x + cur;
	while (!(res = place_piece(infos, pos, 0, 0)) && pos.y < enmy.y + cur)
		pos.y++;
	while (!(res = place_piece(infos, pos, 0, 0)) && pos.x > enmy.x - cur)
		pos.x--;
	while (!(res = place_piece(infos, pos, 0, 0)) && pos.y > enmy.y - cur)
		pos.y--;
	if (res)
		infos->place = pos;
	return (res);
}

int		left_side(t_fill *infos, t_coord enmy, int cur)
{
	int		res;
	t_coord	pos;

	res = 0;
	pos.x = enmy.x + cur;
	pos.y = enmy.y + cur;
	while (!(res = place_piece(infos, pos, 0, 0)) && pos.y > enmy.y - cur)
		pos.y--;
	pos.y = enmy.y + cur;
	while (!(res = place_piece(infos, pos, 0, 0)) && pos.x < enmy.x + cur)
		pos.x--;
	while (!(res = place_piece(infos, pos, 0, 0)) && pos.y > enmy.y - cur)
		pos.y--;
	while (!(res = place_piece(infos, pos, 0, 0)) && pos.x < enmy.x + cur)
		pos.x++;
	if (res)
		infos->place = pos;
	return (res);
}

t_coord	rush_b(t_fill *infos)
{
	t_coord	pos;
	int		res;

	pos.y = infos->gridsize.y;
	res = 0;
	while (!res && pos.y-- > infos->gridsize.y - infos->gridsize.y / 4)
	{
		pos.x = -infos->piecesize.x;
		while (!res && pos.x++ < infos->place.x)
			res = place_piece(infos, pos, 0, 0);
	}
	if (!res)
		pos.x = -9999;
	return (pos);
}

t_coord	side_to_fill_x(t_fill *infos)
{
	t_coord pos;
	t_coord fail;

	pos.x = infos->gridsize.y > 16 ? 0 : infos->gridsize.x / 2;
	pos.y = infos->gridsize.y > 16 ? infos->gridsize.y - 1 : 0;
	fail.x = -9999;
	if (infos->gridsize.y < 16)
		return (fail);
	if ((scan_row(infos, pos.x, infos->player)
			&& scan_row(infos, infos->gridsize.x - 1, infos->player)))
		return (fail);
	if (scan_row(infos, pos.x, infos->player))
		return (infos->enmyinit);
	else if (infos->gridsize.y > 16 && rush_b(infos).x != -9999)
		return (rush_b(infos));
	else
	{
		while (infos->player == 'X' &&
				infos->grid[pos.y] && infos->grid[pos.y][pos.x] != '.')
			pos.y++;
	}
	return (pos);
}

t_coord	side_to_fill_o(t_fill *infos)
{
	t_coord	pos;

	pos.x = infos->gridsize.x - 1;
	pos.y = infos->gridsize.y / 2;
	
	if ((scan_row(infos, pos.x, ENMYCHAR) > infos->gridsize.x / 3)
		|| (scan_row(infos, pos.x, infos->player) && scan_row(infos,
		(pos.x == 0 ? infos->gridsize.x - 1 : 0), infos->player)))
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
