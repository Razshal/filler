/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 13:20:07 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/26 15:31:54 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_fill *structnew(char player, int playernum)
{
	t_fill *new;

	if (!(new = (t_fill*)malloc(sizeof(t_fill))))
		return (NULL);
	new->grid = NULL;
	new->currentline = NULL;
	new->player = player;
	new->playernum = playernum;
	new->gridsize.x = -1;
	new->gridsize.y = -1;
	new->piecesize.x = -1;
	new->piecesize.y = -1;
	new->currentpiece = NULL;
	new->overflow = 0;
	return (new);
}
