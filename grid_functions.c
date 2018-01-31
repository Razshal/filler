/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 10:54:48 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/31 18:51:18 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_coord grid_search(t_fill *infos, char c)
{
	char	**grid;
	int		line;
	int		row;

	line = 0;
	grid = infos->grid;
	while (grid[line++])
	{
		row = 0;
		while (grid[line][row++])
		{
			if (grid[line][row] == c)
			{
				infos->place.y = line;
				infos->place.x = row;
				return (infos->place);
			}
		}
	}
	return (infos->place);
}
