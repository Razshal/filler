/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 17:22:25 by mfonteni          #+#    #+#             */
/*   Updated: 2018/02/20 17:59:11 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	is_on_grid(t_fill *infos, int line, int row)
{
	return (!(line < 0 || row < 0
			|| line > infos->gridsize.y - 1
			|| row > infos->gridsize.x - 1));
}

int	heatmap_grid_search(t_fill *infos, int num)
{
	int line;
	int row;

	line = -1;
	while (++line < infos->gridsize.y)
	{
		row = -1;
		while (++row < infos->gridsize.x)
		{
			if (infos->heatmap[line][row] == num)
				return (1);
		}
	}
	return (0);
}
