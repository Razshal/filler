/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 11:58:25 by mfonteni          #+#    #+#             */
/*   Updated: 2018/02/16 21:03:08 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
/*
static void display_grid(t_fill *infos)
{
	int line = -1;
	int row;

	int i = 0;

	while (++line < infos->gridsize.y)
	{
		dprintf(FD, "LOOP %d\n", i++);
		row = -1;
		while (++row < infos->gridsize.x)
		{
			if (infos->grid[line][row] == PLAYER)
				ft_putchar_fd(infos->player, FD);
			if (infos->grid[line][row] == ENNEMY)
				ft_putchar_fd(ENNEMYCHAR, FD);
			if (infos->grid[line][row] == ENNEMYLASTPOS)
				ft_putchar_fd(ENNEMYPOSCHAR, FD);
			if (infos->grid[line][row] == NOTHING)
				ft_putchar_fd('.', FD);
			if (infos->grid[line][row] == ENDOFTAB)
				ft_putchar_fd('|', FD);
		}
	}
}
*/
int	main(void)
{
	t_fill	*infos;
	char	*str;
	int		res;

	str = NULL;
	res = 1;
	while (!str || (!ft_strstr(str, "mfonteni.filler")
				&& (!ft_strstr(str, "p1") || !ft_strstr(str, "p2"))))
		get_next_line(0, &str);
	infos = (ft_strstr(str, "p1") ? structnew('O') : structnew('X'));
	infos->currentline = str;
	while (res)
	{
		grid_parser(infos);
		piece_parser(infos);
		if (!(res = heatmap_search(infos)))
			ft_putendl("0 0");
		else
			dprintf(FD, "heatmap succes");
	}
	structdel(infos);
}
