/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 16:43:47 by mfonteni          #+#    #+#             */
/*   Updated: 2018/02/16 20:51:41 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void display_grid(t_fill *infos)
{
	int line = -1;
	int row;

	while (++line < infos->gridsize.y)
	{
//		dprintf(FD, "LOOP %d\n", i++);
		row = -1;
		while (++row < infos->gridsize.x)
		{
			if (infos->heatmap[line][row] == PLAYER)
				ft_putchar_fd(infos->player, FD);
			else if (infos->heatmap[line][row] == ENNEMY)
				ft_putchar_fd(ENNEMYCHAR, FD);
			else if (infos->heatmap[line][row] == ENNEMYLASTPOS)
				ft_putchar_fd(ENNEMYPOSCHAR, FD);
			else if (infos->heatmap[line][row] == NOTHING)
				ft_putchar_fd('.', FD);
			else if (infos->heatmap[line][row] > 0)
			{
				dprintf(FD, "%d", infos->heatmap[line][row]);
				fflush(stdout);
			}
			else if (infos->heatmap[line][row] == ENDOFTAB)
				ft_putchar_fd('|', FD);
			ft_putchar_fd('\t', FD);
		}
		ft_putchar_fd('\n', FD);
	}
}
