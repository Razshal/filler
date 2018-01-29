/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 11:58:25 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/29 18:24:02 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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

