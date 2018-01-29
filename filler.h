/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 12:50:49 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/29 13:08:37 by mfonteni         ###   ########.fr       */
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
#define NAME(name) printf("=== %s ===\n", name);
#define SUCCESSMSG "\e[32m[Success]\e[39m\n"
#define PRINTFSUCCESS printf("%s", SUCCESSMSG)
#define FAILUREMSG "\e[31m[Failure]\e[39m\n"
#define PRINTFFAILURE printf("%s", FAILUREMSG)
#define EASYTESTFAIL printf("Echec d'un test de fonctionnement basique\n");
#define INTMIN "-2147483648"
#define INTMAX "2147483647"

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
	char	**currentpiece;
	int		overflow;
	char	**grid;
}				t_fill;

t_fill			*structnew(char player, int playernum);
void			set_grid_size(t_fill *infos);
void			set_piece_size(t_fill *infos);
void			grid_parser(t_fill *infos);
void			piece_parser(t_fill *infos);
int				place_piece(t_fill *infos, t_coord place, int line, int row);

#endif
