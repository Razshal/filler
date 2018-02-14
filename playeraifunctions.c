/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playeraifunctions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 12:04:16 by mfonteni          #+#    #+#             */
/*   Updated: 2018/02/14 18:48:38 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	right_side(t_fill *infos, t_coord enmy, int cur)
{
	int res;
	t_coord pos;

	res = 0;
	pos.x = enmy.x - cur;
	pos.y = enmy.y - cur;
	while (!(res = place_piece(infos, pos, 0, 0)) && pos.y > enmy.y - cur)
		pos.y--;
	pos.y = enmy.y - cur;
	while (!(res = place_piece(infos, pos, 0, 0)) && pos.x < enmy.x + cur)
		pos.x++;
	while (!(res = place_piece(infos, pos, 0, 0)) && pos.y > enmy.y - cur)
		pos.y--;
	while (!(res = place_piece(infos, pos, 0, 0)) && pos.x > enmy.x - cur)
		pos.x--;
	if (res)
		infos->place = pos;
	return (res);
}

int	left_side(t_fill *infos, t_coord enmy, int cur)
{
	int res;
	t_coord pos;

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

t_coord	side_to_fill_x(t_fill *infos)
{
	t_coord	pos;
	t_coord fail;

	pos.x = 0;
	pos.y = infos->gridsize.y - 1;
	fail.x = -1;
	fail.y = -1;
	if ((scan_row(infos, pos.y, infos->player)
			&& scan_row(infos, infos->gridsize.x - 1, infos->player)))
		return (fail);
	if (scan_row(infos, pos.x, infos->player))
	{
		pos.y = infos->playerinit.y;
		pos.x = infos->gridsize.x - 1;
		return (pos);
	}
	else if (!(scan_row(infos, pos.x, infos->player)))
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
	t_coord fail;

	pos.x = infos->gridsize.x - 1;
	pos.y = infos->gridsize.y - infos->gridsize.y / 3;
	fail.x = -1;
	fail.y = -1;
	if ((scan_row(infos, pos.y, infos->player)
			&& scan_row(infos, 0, infos->player)))
		return (fail);
	if (scan_row(infos, pos.x, infos->player))
	{
		pos.y = infos->playerinit.y;
		pos.x = 0;
		return (pos);
	}
	else if (!(scan_row(infos, pos.x, infos->player)))
	{
		while (pos.y > -1 && infos->grid[pos.y][pos.x] != '.')
			pos.y--;
	}
	return (pos);
}
