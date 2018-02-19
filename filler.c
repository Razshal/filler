/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 11:58:25 by mfonteni          #+#    #+#             */
/*   Updated: 2018/02/19 18:40:11 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	main(void)
{
	t_fill	*infos;
	char	*str;
	int		res;
	int		first_turn;

	str = NULL;
	res = 1;
	first_turn = 1;
	while (!str || (!ft_strstr(str, "mfonteni.filler")
				&& (!ft_strstr(str, "p1") || !ft_strstr(str, "p2"))))
		get_next_line(0, &str);
	infos = (ft_strstr(str, "p1") ? structnew('O') : structnew('X'));
	infos->currentline = str;
	while (res)
	{
		grid_parser(infos);
		piece_parser(infos);
		res = heatmap_search(infos, first_turn);
		first_turn = 0;
		if (!res)
			res = fallback_player(infos);
	}
	ft_putendl("0 0");
	structdel(infos);
}
