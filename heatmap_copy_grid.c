/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap_copy_grid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 19:39:50 by mfonteni          #+#    #+#             */
/*   Updated: 2018/02/20 18:00:31 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	create_array(t_fill *infos)
{
	int line;

	line = 0;
	if (!infos->heatmap &&
			!(infos->heatmap = new_twodim_array(infos->gridsize.y)))
		return (0);
	while (line < infos->gridsize.y)
	{
		if (!infos->heatmap[line] &&
				!(infos->heatmap[line] = newarray(infos->gridsize.x)))
			return (0);
		line++;
	}
	return (1);
}

int			heatmap_init(t_fill *infos)
{
	int line;
	int row;

	line = -1;
	if (!infos->heatmap && !create_array(infos))
		return (0);
	while (infos->grid[++line])
	{
		row = -1;
		while (infos->grid[line][++row])
		{
			if (infos->grid[line][row] == GRIDNOTHING)
				infos->heatmap[line][row] = NOTHING;
			else if (infos->grid[line][row] == ENNEMYCHAR)
				infos->heatmap[line][row] = ENNEMY;
			else if (infos->grid[line][row] == ENNEMYPOSCHAR)
				infos->heatmap[line][row] = ENNEMYLASTPOS;
		}
	}
	return (1);
}

char		*fill_array_lines(t_fill *infos, char *dst, const char *src)
{
	int count;

	count = 0;
	while (src[count] != '\0')
	{
		if (dst[count] == '.' && src[count] == ENNEMYCHAR)
			dst[count] = ENNEMYPOSCHAR;
		else
			dst[count] = src[count];
		count++;
	}
	dst[count] = '\0';
	return (dst);
}
