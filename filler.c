/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 11:58:25 by mfonteni          #+#    #+#             */
/*   Updated: 2018/02/01 16:37:32 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
/*
static void get_closest_coordinates_from_ennemy(t_fill *infos)
{
	if (ennemy.x < infos->place.x)

}

static t_coord get_and_print_coordinates(t_fill *infos)
{
	t_coord place;

	if (infos->place.x = -9999)
		infos->place = grid_search(infos, infos->player);



}*/

static void default_player(t_fill *infos)
{
	t_coord	place;
	int		result;

	place.y = -1;
	result = 0;
	while (!result && place.y++ < infos->gridsize.y)
	{
		place.x = -1;
		while ((result = place_piece(infos, place, 0, 0)) != 1 &&
				place.x < infos->gridsize.x)
		{
			place.x++;
			infos->overflow = 0;
		}
	}
	ft_printf("%d %d\n", place.y, place.x);
}

int main(void)
{
	t_fill	*infos;
	char	*str;

	str = NULL;
	while (!str || (!ft_strstr(str, "mfonteni.filler")
				&& (!ft_strstr(str, "p1") || !ft_strstr(str, "p2"))))
		get_next_line(0, &str);
	infos = (ft_strstr(str, "p1") ? structnew('O', 0) : structnew('X', 1));
	infos->currentline = str;
	while (!ft_strstr(infos->currentline, "== O fin"))
	{
		grid_parser(infos);
		piece_parser(infos);
		default_player(infos);
	}
}

