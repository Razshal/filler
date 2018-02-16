/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 17:22:25 by mfonteni          #+#    #+#             */
/*   Updated: 2018/02/16 17:40:53 by mfonteni         ###   ########.fr       */
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
