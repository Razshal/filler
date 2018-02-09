/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playerai.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 12:17:39 by mfonteni          #+#    #+#             */
/*   Updated: 2018/02/09 13:44:32 by mfonteni         ###   ########.fr       */
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
/*
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
	usleep(50000);
	infos->place = place;
	return (1);
}
*/
/*
static void	whereami(t_fill *infos, t_coord pos)
{
	char c;
	if (pos.y < infos->gridsize.y && pos.x < infos->gridsize.x && pos.y >= 0 && pos.x >= 0)
	{
		c = infos->grid[pos.y][pos.x];
		infos->grid[pos.y][pos.x] = 'A';
	}
	else c = -1;
	ft_print_split_fd(infos->grid, FD);
	if (c > -1)
		infos->grid[pos.y][pos.x] = c;
	usleep(5000);
}
*/

static int	arround_ennemy_left(t_fill *infos)
{
	t_coord	ennemy;
	int		res;
	int		tries;
	t_coord	pos;

	tries = -1;
	res = 0;
	ennemy = ennemypos(infos);
	while (!res && (tries < infos->piecesize.y + infos->gridsize.y
				|| tries < infos->piecesize.x + infos->gridsize.x))
	{
		pos.x = ennemy.x - ++tries;
		pos.y = ennemy.y - tries;
		while (!(res = place_piece(infos, pos, 0, 0)) && pos.y < ennemy.y + tries)
			pos.y++;
		while (!(res = place_piece(infos, pos, 0, 0)) && pos.x < ennemy.x + tries)
			pos.x++;
		while (!(res = place_piece(infos, pos, 0, 0)) && pos.y > ennemy.y - tries)
			pos.y--;
		while (!(res = place_piece(infos, pos, 0, 0)) && pos.x > ennemy.x - tries)
			pos.x--;
	}
	if (!res)
		return (0);
	ft_printf("%d %d\n", pos.y, pos.x);
	return (1);
}

static int	arround_ennemy_right(t_fill *infos)
{
	t_coord	ennemy;
	int		res;
	int		tries;
	t_coord	pos;

	tries = -1;
	res = 0;
	ennemy = ennemypos(infos);
	while (!res && (tries < infos->piecesize.y + infos->gridsize.y
				|| tries < infos->piecesize.x + infos->gridsize.x))
	{
		pos.x = ennemy.x - ++tries;
		pos.y = ennemy.y - tries;
		while (!(res = place_piece(infos, pos, 0, 0)) && pos.y < ennemy.y + tries)
			pos.y++;
		while (!(res = place_piece(infos, pos, 0, 0)) && pos.x < ennemy.x + tries)
			pos.x++;
		while (!(res = place_piece(infos, pos, 0, 0)) && pos.y > ennemy.y - tries)
			pos.y--;
		while (!(res = place_piece(infos, pos, 0, 0)) && pos.x > ennemy.x - tries)
			pos.x--;
	}
	if (!res)
		return (0);
	ft_printf("%d %d\n", pos.y, pos.x);
	return (1);
}


int	player_ai(t_fill *infos)
{
	if (arround_ennemy(infos))
		return (1);
//	else if (default_player(infos))
//		return (1);
	ft_putendl("0 0");
	dprintf(FD, "FAIL");
	return (0);
}
