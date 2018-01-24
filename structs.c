/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 13:20:07 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/24 16:02:06 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_fill *structnew(char player, int playernum)
{
	t_fill *new;

	if (!(new = (t_fill*)malloc(sizeof(t_fill))))
		return (NULL);
	new->currentline = NULL;
	new->player = player;
	new->playernum = playernum;
	new->sizex = -1;
	new->sizey = -1;
	return (new);
}
