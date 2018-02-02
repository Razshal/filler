/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playerai.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 12:17:39 by mfonteni          #+#    #+#             */
/*   Updated: 2018/02/02 15:32:38 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	close_to_the_ennemy(t_fill *infos)
{
	t_coord	ennemy;
	t_coord	try;
	int res;

	try = infos->place;
	res = 0;
	ennemy = grid_search(infos, (infos->player = 'X' ? 'o' : 'x'));
	if (ennemy.x < 0)
		ennemy = grid_search(infos, (infos->player = 'X' ? 'O' : 'X'));
	while (try.x != ennemy.x && try.y != ennemy.y)
	{
		ennemy.x < try.x ? try.x-- : 0;
		ennemy.x > try.x ? try.x++ : 0;
		ennemy.y < try.y ? try.y-- : 0;
		ennemy.y > try.y ? try.y++ : 0;
		if ((res = place_piece(infos, try, 0, 0)))
		{
			ft_printf("%d %d\n", try.y, try.x);
			return (1);
		}
	}
	return (0);
}

static int default_player(t_fill *infos)
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
		{
			place.x++;
			infos->overflow = 0;
		}
	}
	if (!result)
	{
		ft_putstr("0 0");
		return (0);
	}
	ft_printf("%d %d\n", place.y, place.x);
	infos->place = place;
	return (1);
}

int	player_ai(t_fill *infos)
{
	if (close_to_the_ennemy(infos))
		return (1);
	else if (default_player(infos))
		return (1);
	return (0);
}

