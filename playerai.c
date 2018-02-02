/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playerai.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 12:17:39 by mfonteni          #+#    #+#             */
/*   Updated: 2018/02/02 13:54:54 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void get_closest_coordinates_from_ennemy(t_fill *infos)
{
	int		leftside;
	t_coord	ennemy;

	ennemy = grid_search(infos, (infos->player = 'X' ? 'o' : 'x'));
	if (ennemy.x < 0)
		ennemy = grid_search(infos, (infos->player = 'X' ? 'O' : 'X'));
	leftside = ennemy.x < infos->place.x ? 1 : 0;
	//if he's on left try from begin to me, if he's on right try from me to begin


	ft_memdel((void*)&ennemy);
}
