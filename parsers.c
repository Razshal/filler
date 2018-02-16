/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 16:31:46 by mfonteni          #+#    #+#             */
/*   Updated: 2018/02/16 13:30:50 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static char	**init_first_dim(int size)
{
	char **new;

	if (!(new = (char**)malloc(sizeof(char*) * size)))
		return (NULL);
	while (size)
		new[--size] = NULL;
	return (new);
}

void		set_grid_size(t_fill *infos)
{
	char	*temp;
	int		count;

	count = 0;
	while (!ft_strstr(infos->currentline, "Plateau"))
		get_next_line(0, &infos->currentline);
	temp = &ft_strstr(infos->currentline, "Plateau")[7];
	infos->gridsize.y = ft_atoi(temp);
	while (ft_ispace(temp[count]))
		count++;
	while (ft_isdigit(temp[count]))
		count++;
	while (ft_ispace(temp[count]))
		count++;
	infos->gridsize.x = ft_atoi(&temp[count]);
}

void		set_piece_size(t_fill *infos)
{
	char	*temp;
	int		count;

	count = 0;
	while (!ft_strstr(infos->currentline, "Piece"))
		get_next_line(0, &infos->currentline);
	temp = &ft_strstr(infos->currentline, "Piece")[6];
	infos->piecesize.y = ft_atoi(temp);
	while (ft_ispace(temp[count]))
		count++;
	while (ft_isdigit(temp[count]))
		count++;
	while (ft_ispace(temp[count]))
		count++;
	infos->piecesize.x = ft_atoi(&temp[count]);
}

void		grid_parser(t_fill *infos)
{
	int		line;

	line = 0;
	if (infos->gridsize.y == -1)
		set_grid_size(infos);
	if (!(infos->grid = init_first_dim(infos->gridsize.y + 1)))
		return ;
	while (line < infos->gridsize.y)
	{
		if (!infos->grid[line])
			infos->grid[line] = ft_strnew(infos->gridsize.x + 1);
		if (infos->grid[line] && ft_isdigit(*infos->currentline))
			ft_strcpy(infos->grid[line++], &infos->currentline[4]);
		get_next_line(0, &infos->currentline);
	}
}

void		piece_parser(t_fill *infos)
{
	int		line;

	line = 0;
	set_piece_size(infos);
	while (infos->currentpiece && infos->currentpiece[line++])
		ft_memdel((void*)&infos->currentpiece[line]);
	ft_memdel((void**)infos->currentpiece);
	line = 0;
	if (!(infos->currentpiece = init_first_dim(infos->piecesize.y + 1)))
		return ;
	while (infos->piecesize.y > line)
	{
		get_next_line(0, &infos->currentline);
		infos->currentpiece[line] = ft_strnew(infos->piecesize.x + 1);
		ft_strcpy(infos->currentpiece[line], infos->currentline);
		line++;
	}
	infos->currentpiece[line] = 0;
}
