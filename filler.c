/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 11:58:25 by mfonteni          #+#    #+#             */
/*   Updated: 2018/02/20 11:45:21 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	main(void)
{
	t_fill	*infos;
	char	*str;
	int		res;

	str = NULL;
	res = 1;
	while (!str || (!ft_strstr(str, "mfonteni.filler")
				&& (!ft_strstr(str, "p1") || !ft_strstr(str, "p2"))))
	{
		ft_memdel((void**)&str);
		get_next_line(0, &str);
	}
	infos = (ft_strstr(str, "p1") ? structnew('O') : structnew('X'));
	infos->currentline = str;
	while (res)
	{
		if (!grid_parser(infos) || !piece_parser(infos))
			break;
		ft_print_split_fd(infos->grid, FD);
		res = heatmap_search(infos);
		if (!res)
			res = fallback_player(infos);
	}
	ft_putendl("0 0");
	structdel(infos);
}
