/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 12:50:49 by mfonteni          #+#    #+#             */
/*   Updated: 2018/02/12 19:28:54 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
#define FILLER_H
#include "libft/includes/libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define FD open("/dev/ttys000", O_RDWR)
#define CLOSE close(FD)

#define ENMYCHAR (infos->player == 'X' ? 'X' : 'O')

typedef struct	s_coord
{
	int x;
	int y;
}				t_coord;

typedef	struct	s_fill
{
	char	*currentline;
	char	player;
	int		playernum;
	t_coord	gridsize;
	t_coord	piecesize;
	t_coord	place;
	t_coord	playerinit;
	t_coord	enmyinit;
	char	**currentpiece;
	int		overflow;
	char	**grid;
}				t_fill;

t_fill			*structnew(char player, int playernum);
void			structdel(t_fill *struc);
void			set_grid_size(t_fill *infos);
void			set_piece_size(t_fill *infos);
void			grid_parser(t_fill *infos);
void			piece_parser(t_fill *infos);
int				place_piece(t_fill *infos, t_coord place, int line, int row);
t_coord			grid_search(t_fill *infos, char c);
int				player_ai(t_fill *infos);
t_coord			enmypos(t_fill *infos);
void			initpos(t_fill *infos);
t_coord			side_to_fill(t_fill *infos);
int				scan_row(t_fill *infos, int x, char c);

#endif
