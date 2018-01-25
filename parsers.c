/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 16:31:46 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/25 17:02:50 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	set_grid_size(t_fill *infos)
{
	char	*temp;
	int		count;

	count = 0;
	while (!ft_strstr(infos->currentline, "Plateau"))
		get_next_line(0, &infos->currentline);
	infos->sizex = ft_atoi((temp = ft_strstr(infos->currentline, "Plateau")));
	temp++;
	while (ft_isdigit(temp[count]))
		count++;
	while (ft_ispace(temp[count]))
		count++;
	infos->sizey = ft_atoi(&temp[count]);
}

void	set_piece_size(t_fill *infos)
{
	char	*temp;
	int		count;

	count = 0;
	while (!ft_strstr(infos->currentline, "Piece"))
		get_next_line(0, &infos->currentline);
	infos->piecesizex = ft_atoi((temp =
			ft_strstr(infos->currentline, "Piece")));
	temp++;
	while (ft_isdigit(temp[count]))
		count++;
	while (ft_ispace(temp[count]))
		count++;
	infos->piecesizey = ft_atoi(&temp[count]);
}

void	grid_parser(t_fill *infos)
{
	int		line;

	line = 0;
	if (infos->sizex == -1)
		set_grid_size(infos);
	if (!(infos->grid = (char**)malloc(sizeof(char*) * infos->sizex + 1)))
		return ;
	while (line < infos->sizex)
	{
		if (!infos->grid[line])
			infos->grid[line] = ft_strnew(infos->sizey + 1);
		if (infos->grid[line] && ft_isdigit((infos->currentline)[0]))
			ft_strcat(infos->grid[line++], &(infos->currentline)[4]);
		else
			break;
		get_next_line(0, &infos->currentline);
	}
}

void	piece_parser(t_fill *infos)
{
	int		line;

	line = 0;
	set_piece_size(infos);
	if (!(infos->currentpiece
				= (char**)malloc(sizeof(char*) * infos->piecesizex + 1)))
		return ;
	while (line < infos->piecesizex)
	{
		if (!infos->currentpiece[line])
			infos->currentpiece[line] = ft_strnew(infos->piecesizey + 1);
		if (infos->currentpiece[line] && !ft_strstr(infos->currentline, "<got"))
			ft_strcat(infos->currentpiece[line++], infos->currentline);
		else
			break;
		get_next_line(0, &infos->currentline);
	}
}
