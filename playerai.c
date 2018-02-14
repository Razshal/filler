/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playerai.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 12:17:39 by mfonteni          #+#    #+#             */
/*   Updated: 2018/02/14 12:48:06 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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

static int	border_player(t_fill *infos)
{
	t_coord	enmy;
	int		res;
	int		cur;

	cur = 0;
	res = 0;
	enmy = side_to_fill(infos);
	while (!res && enmy.x != -1
			&& (cur < infos->piecesize.y + infos->gridsize.y
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

int	player_ai(t_fill *infos)
{
	t_coord enmy;
	static int bord = 0;
	static int arround = 0;
	static int defaultp = 0;

	enmy = enmypos(infos);
	if (border_player(infos))
	{
		dprintf(FD, "borderplayer %d\n", bord++); fflush(stdout);
		return (1);
	}
	else if (arround_enmy(infos))
	{
		dprintf(FD, "arround enmy %d\n", arround++);
		return (1);
	}
	else if (default_player(infos))
	{
		dprintf(FD, "default player %d\n", defaultp++);
		return (1);
	}
	ft_putendl("0 0");
	return (0);
}
