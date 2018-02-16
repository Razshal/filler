/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fallback_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 14:25:10 by mfonteni          #+#    #+#             */
/*   Updated: 2018/02/16 14:27:16 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	default_player(t_fill *infos)
{
	t_coord	place;
	int		result;

	place.y = -infos->piecesize.y;
	result = 0;
	while (!result && place.y++ < infos->gridsize.y + 5)
	{
		place.x = -infos->piecesize.x;
		while ((result = place_piece(infos, place, 0, 0)) != 1
				&& place.x < infos->gridsize.x + 5)
			place.x++;
	}
	if (!result)
		return (0);
	ft_printf("%d %d\n", place.y, place.x);
	infos->place = place;
	return (1);
}
