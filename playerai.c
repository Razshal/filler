/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playerai.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 12:17:39 by mfonteni          #+#    #+#             */
/*   Updated: 2018/02/03 16:56:00 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static t_coord	ennemypos(t_fill *infos)
{
	t_coord ennemy;

	ennemy = grid_search(infos, (infos->player == 'X' ? 'o' : 'x'));
	if (ennemy.x < 0)
		ennemy = grid_search(infos, (infos->player == 'X' ? 'O' : 'X'));
	return (ennemy);
}

static int	close_to_the_ennemy(t_fill *infos)
{
	t_coord	ennemy;
	t_coord	try;

	try = infos->place;
	ennemy = ennemypos(infos);
	while (try.x != ennemy.x && try.y != ennemy.y)
	{
		ennemy.x < try.x ? try.x-- : 0;
		ennemy.x > try.x ? try.x++ : 0;
		ennemy.y < try.y ? try.y-- : 0;
		ennemy.y > try.y ? try.y++ : 0;
		if (place_piece(infos, try, 0, 0) == 1)
		{
			ft_printf("%d %d\n", try.y, try.x);
			return (1);
		}
	}
	return (0);
}

static int	search_in_subgrid(t_fill *infos)
{
	t_coord	try;
	t_coord	ennemy;
	int		res;
	res = 0;
	ennemy = ennemypos(infos);
	try = ennemy;
	while (try.y != infos->place.y - (infos->piecesize.y < infos->place.y ?
				-infos->piecesize.y : infos->piecesize.y) && !res)
	{
		try.x = ennemy.x;
		while (!(res = place_piece(infos, try, 0, 0)) && try.x < infos->place.x)
			try.x++;
		while (!(res = place_piece(infos, try, 0, 0)) && try.x > infos->place.x)
			try.x--;
		if (!res)
			try.y = try.y < infos->place.y - (infos->piecesize.y < infos->place.y ?
				-infos->piecesize.y : infos->piecesize.y) ? try.y + 1 : try.y - 1;
	}
	if (res)
		ft_printf("%d %d\n", try.y, try.x);
	return (res);
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
	static int i = 0;
	if (close_to_the_ennemy(infos))
		return (1);
	else if (search_in_subgrid(infos))
	{
		dprintf(FD, "Success %d\n", i++);
		return (1);
	}
	else if (default_player(infos))
		return (1);
	ft_putendl("0 0");
	return (0);
}
