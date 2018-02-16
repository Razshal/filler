/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap_copy_grid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 19:39:50 by mfonteni          #+#    #+#             */
/*   Updated: 2018/02/16 19:42:11 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		create_array(t_fill *infos)
{
	int line;

	line = 0;
	if (!(infos->heatmap = new_twodim_array(infos->gridsize.y)))
		return (0);
	while (line < infos->gridsize.y)
	{
		if (!infos->heatmap[line] &&
				(!(infos->heatmap[line] = newarray(infos->gridsize.x))))
			return (0);
		line++;
	}
	return (1);
}

int		heatmap_init(t_fill *infos)
{
	int line;
	int row;

	line = 0;
	row = 0;
	while (line < infos->gridsize.y)
}
