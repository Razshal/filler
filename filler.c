/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 11:58:25 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/25 13:47:21 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	set_grid_size(t_fill *infos)
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

static void	set_piece_size(t_fill *infos)
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

static char	**grid_parser(t_fill *infos)
{
	char	**grid;
	int		line;

	line = 0;
	if (infos->sizex == -1)
		set_grid_size(infos);
	if (!(grid = (char**)malloc(sizeof(char*) * infos->sizex + 1)))
		return (NULL);
	while (line < infos->sizex)
	{
		if (!grid[line])
			grid[line] = ft_strnew(infos->sizey + 1);
		if (grid[line] && ft_isdigit((infos->currentline)[0]))
		{
			ft_strcat(grid[line], &(infos->currentline)[4]);
			line++;
		}
		else
			get_next_line(0, &infos->currentline);
	}
	return (grid);
}

static char	*piece_parser(t_fill *infos)
{

}

int main(void)
{
	t_fill	*infos;
	char	**grid;
	char	*str;

	while (!str || (!ft_strstr(str, "mfonteni")
				&& (!ft_strstr(str, "p1") ||
					!ft_strstr(str, "p2"))))
		get_next_line(0, &infos->currentline);
	if (ft_strstr(infos->currentline, "p1"))
		infos = structnew('O', 1);
	else
		infos = structnew('X', 2);
	infos->currentline = str;
	while (!ft_strstr(infos->currentline, "fin"))
	{
		grid_parser(infos);
		piece_parser(infos);
	}


}
