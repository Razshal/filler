/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 16:31:46 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/29 17:02:28 by mfonteni         ###   ########.fr       */
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
	infos->gridsize.y =
		ft_atoi((temp = ft_strstr(infos->currentline, "Plateau")));
	temp++;
	while (ft_isdigit(temp[count]))
		count++;
	while (ft_ispace(temp[count]))
		count++;
	infos->gridsize.x = ft_atoi(&temp[count]);
}

void	set_piece_size(t_fill *infos)
{
	char	*temp;
	int		count;

	count = 0;
	while (!ft_strstr(infos->currentline, "Piece"))
		get_next_line(0, &infos->currentline);
	infos->piecesize.y = ft_atoi((temp =
			ft_strstr(infos->currentline, "Piece")));
	temp++;
	while (ft_isdigit(temp[count]))
		count++;
	while (ft_ispace(temp[count]))
		count++;
	infos->piecesize.x = ft_atoi(&temp[count]);
}

void	grid_parser(t_fill *infos)
{
	int		line;

	line = 0;
	if (infos->gridsize.y == -1)
		set_grid_size(infos);
	if (!(infos->grid = (char**)malloc(sizeof(char*) * infos->gridsize.y + 2)))
		return ;
	while (line < infos->gridsize.y)
	{
		if (!infos->grid[line])
			infos->grid[line] = ft_strnew(infos->gridsize.x + 1);
		if (infos->grid[line] && ft_isdigit((infos->currentline)[0]))
			ft_strcat(infos->grid[line++], &(infos->currentline)[4]);
		else
			break;
		get_next_line(0, &infos->currentline);
	}
	infos->grid[line] = 0;
}

void	piece_parser(t_fill *infos)
{
	int		line;

	line = 0;
	set_piece_size(infos);
	if (!(infos->currentpiece
				= (char**)malloc(sizeof(char*) * infos->piecesize.x + 2)))
		return ;
	while (line < infos->piecesize.y)
	{
		if (!infos->currentpiece[line])
			infos->currentpiece[line] = ft_strnew(infos->piecesize.x + 1);
		if (infos->currentpiece[line] && !ft_strstr(infos->currentline, "<got"))
			ft_strcat(infos->currentpiece[line++], infos->currentline);
		else
			break;
		get_next_line(0, &infos->currentline);
	}
	infos->currentpiece[line] = 0;
}
