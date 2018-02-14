/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playeraifunctions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 12:04:16 by mfonteni          #+#    #+#             */
/*   Updated: 2018/02/14 13:18:47 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	right_side(t_fill *infos, t_coord enmy, int cur)
{
	int res;
	t_coord pos;

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

int	default_player(t_fill *infos)
{
	t_coord	place;
	int		result;

	place.y = -infos->piecesize.y;
	result = 0;
	while (!result && place.y++ < infos->gridsize.y + 5)
	{
		place.x = -infos->piecesize.x;
		while ((result = place_piece(infos, place, 0, 0)) != 1
				&& place.x < infos->gridsize.x + 5)
			place.x++;
	}
	if (!result)
		return (0);
	ft_printf("%d %d\n", place.y, place.x);
	infos->place = place;
	return (1);
}

t_coord	side_to_fill(t_fill *infos)
{
	t_coord	pos;

	pos.x = infos->playerinit.x < infos->enmyinit.x ? infos->gridsize.x - 1 : 0;
	pos.y = infos->player == 'X' ?
		infos->gridsize.y - 1 : infos->gridsize.y - infos->gridsize.y / 3;
	if ((scan_row(infos, pos.x, ENMYCHAR) > infos->gridsize.x / 2)
		|| (scan_row(infos, pos.y, infos->player) && scan_row(infos,
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
		while (infos->grid[pos.y] && infos->grid[pos.y][pos.x] != '.')
			pos.y++;
	}
	return (pos);
}
