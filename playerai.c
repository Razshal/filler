/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playerai.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 12:17:39 by mfonteni          #+#    #+#             */
/*   Updated: 2018/02/09 19:03:53 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	right_side(t_fill *infos, t_coord enmy, int cur)
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

static int	left_side(t_fill *infos, t_coord enmy, int cur)
{
	int res;
	t_coord pos;

	res = 0;
	pos.x = enmy.x - cur;
	pos.y = enmy.y + cur;
	while (!(res = place_piece(infos, pos, 0, 0)) && pos.x < enmy.x + cur)
		pos.x++;
	pos.x = enmy.x - cur;
	while (!(res = place_piece(infos, pos, 0, 0)) && pos.y > enmy.y - cur)
		pos.y--;
	while (!(res = place_piece(infos, pos, 0, 0)) && pos.x < enmy.x + cur)
		pos.x++;
	while (!(res = place_piece(infos, pos, 0, 0)) && pos.y < enmy.y + cur)
		pos.y++;
	if (res)
		infos->place = pos;
	return (res);
}

static int	arround_enmy(t_fill *infos)
{
	t_coord	enmy;
	int		res;
	int		cur;

	cur = 0;
	res = 0;
	enmy = enmypos(infos);
	while (!res && (cur < infos->piecesize.y + infos->gridsize.y
				|| cur < infos->piecesize.x + infos->gridsize.x))
	{
		if (infos->place.y < enmy.y)
			res = right_side(infos, enmy, cur);
		else
			res = left_side(infos, enmy, cur);
		cur++;
	}
	if (!res)
		return (0);
	ft_printf("%d %d\n", infos->place.y, infos->place.x);
	return (1);
}

static int	default_player(t_fill *infos)
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

int	player_ai(t_fill *infos)
{
	t_coord enmy;

	enmy = enmypos(infos);
	if (arround_enmy(infos))
		return (1);
	else if (default_player(infos))
		return (1);
	ft_putendl("0 0");
	return (0);
}
