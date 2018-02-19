/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 17:22:25 by mfonteni          #+#    #+#             */
/*   Updated: 2018/02/19 17:24:17 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	is_on_grid(t_fill *infos, int line, int row)
{
	if (line < 0 || row < 0
			|| line > infos->gridsize.y - 1 || row > infos->gridsize.x - 1)
		return (0);
	return (1);
}

int heatmap_grid_search(t_fill *infos, int num)
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

int grid_search(t_fill *infos, char c)
{
	int line;
	int row;

	line = -1;
	ft_print_split_fd(infos->grid, FD);
	while (++line < infos->gridsize.y)
	{
		row = -1;
		while (++row < infos->gridsize.x)
		{
			if (infos->grid[line][row] == c)
				return (1);
		}
	}
	return (0);
}
