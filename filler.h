/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 12:50:49 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/24 16:01:59 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
#define FILLER_H
#include "libft/includes/libft.h"

typedef	struct	s_fill
{
	char	*currentline;
	char	player;
	int		playernum;
	int		sizex;
	int		sizey;
}				t_fill;

t_fill			*structnew(char player, int playernum);


#endif
