/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 12:50:49 by mfonteni          #+#    #+#             */
/*   Updated: 2018/02/20 11:43:01 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft/includes/libft.h"
# define GRIDNOTHING '.'
# define ENDOFTAB 0
# define NOTHING -1
# define PLAYER -2
# define ENNEMY -3
# define ENNEMYLASTPOS -4
# define PLAYERCHAR (infos->player)
# define ENNEMYCHAR (infos->player == 'X' ? 'O' : 'X')
# define ENNEMYPOSCHAR (ENNEMYCHAR + 32)
# define ISPLACABLE(something) (something == NOTHING || something > 0 ? 1 : 0)

typedef struct	s_coord
{
	int x;
	int y;
}				t_coord;

typedef	struct	s_fill
{
	char	*currentline;
	char	player;
	t_coord	gridsize;
	t_coord	piecesize;
	t_coord place;
	char	**currentpiece;
	int		overflow;
	char	**grid;
	int		**heatmap;
}				t_fill;

///////////////////-DEBUG-////////////////////////
#include <stdio.h>
#include <fcntl.h>
#define FD open("/dev/ttys001", O_RDWR)
void display_grid(t_fill *infos);
////////////////////////////////////////////////////

t_fill			*structnew(char player);
void			structdel(t_fill *struc);
void			set_grid_size(t_fill *infos);
void			set_piece_size(t_fill *infos);
int				grid_parser(t_fill *infos);
int				piece_parser(t_fill *infos);
int				place_piece(t_fill *infos, t_coord place, int line, int row);
int				place_and_decal(t_fill *infos, t_coord pos);
int				fallback_player(t_fill *infos);
int				*newarray(int size);
int				**new_twodim_array(int size);
char			**init_piece(int size);
int				heatmap_search(t_fill *infos);
int				heatmap_init(t_fill *infos);
int				is_on_grid(t_fill *infos, int line, int row);
int				heatmap_grid_search(t_fill *infos, int num);
int				grid_search(t_fill *infos, char c);
char			*fill_array_lines(t_fill *infos, char *dst, const char *src);
#endif
