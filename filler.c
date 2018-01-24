/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 11:58:25 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/24 18:25:51 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	set_grid_size(char *str, t_fill *infos)
{
	char	*temp;
	int		count;

	count = 0;
	while (!ft_strstr(str, "Plateau"))
		get_next_line(0, &str);
	infos->sizex = ft_atoi((temp = ft_strstr(str, "Plateau")));
	temp++;
	while (ft_isdigit(temp[count]))
		count++;
	while (ft_ispace(temp[count]))
		count++;
	infos->sizey = ft_atoi(&temp[count]);
}

static char	**grid_parser(t_fill *infos)
{
	char	**grid;
	int		line;

	line = 0;
	if (infos->sizex == -1)
		set_grid_size(infos->currentline, infos);
	if (!(grid = (char**)malloc(sizeof(char*) * infos->sizex)))
		return (NULL);
	while (line < infos->sizex)
	{
		if (!grid[line])
			grid[line] = ft_strnew(infos->sizey);
		if (ft_isdigit((infos->currentline)[0]))
		{
			ft_strcat(grid[line], &(infos->currentline)[4]);
			line++;
		}
		else
			get_next_line(0, &infos->currentline);
	}

	return (grid);
}

int main(void)
{
	t_fill	*infos;
	char	**grid;
	char	*str;

	str = NULL;
	while (!str || (!ft_strstr(str, "mfonteni")
				&& (!ft_strstr(str, "p1") || !ft_strstr(str, "p2"))))
		get_next_line(0, &str);
	if (ft_strstr(str, "p1"))
		infos = structnew('O', 1);
	else
		infos = structnew('X', 2);
	infos->currentline = str;
	grid_parser(infos);

}
