/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 11:58:25 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/29 17:03:59 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int place_piece(t_fill *infos, t_coord place, int line, int row)
{
	int res;

	res = 0;
	printf("line:%d, row:%d\n", line + place.y, row + place.x);
	if (!infos->currentpiece[line] && infos->overflow == 1)
		return (1);
	else if ((!infos->currentpiece[line] && infos->overflow != 1) ||
			(infos->currentpiece[line][row] == '*' && line + place.y < 0) ||
			(infos->currentpiece[line][row] == '*' && row + place.x < 0))
		return (0);
	if (infos->currentpiece[line][row] == '*' &&
			infos->grid[line + place.y][row + place.x] == infos->player)
		infos->overflow++;
	if (line + place.y > infos->gridsize.y || infos->overflow > 1)
		return (0);
	if (row < infos->piecesize.x)
		res = place_piece(infos, place, line, ++row);
	else if (line < infos->piecesize.y)
		res = place_piece(infos, place, ++line, 0);
	if (res == 1 && infos->grid[line + place.y][row + place.x] == '.')
		return (1);
	else if (res == 0)
		return (0);
	return (res);
}
/*
static void get_closest_coordinates_from_ennemy()
{
	t_coord lastpos = search_my_last_block();


}

static void get_and_print_coordinates(t_fill *infos)
{
	
}

int main(void)
{
	t_fill	*infos;
	char	*str;

	str = NULL;
	while (!str || (!ft_strstr(str, "mfonteni")
				&& (!ft_strstr(str, "p1") || !ft_strstr(str, "p2"))))
		get_next_line(0, &str);
	infos = ft_strstr(str, "p1") ? structnew('O', 1) : structnew('X', 2);
	infos->currentline = str;
	while (!ft_strstr(infos->currentline, "fin"))
	{
		grid_parser(infos);
		piece_parser(infos);
		while (!ft_strstr(infos->currentline, "got"))
			get_next_line(0, &infos->currentline);
		if ((ft_strstr(infos->currentline, "<got ("))[0] == infos->player)
			get_and_print_coordinates(infos);
	}
}
*/
