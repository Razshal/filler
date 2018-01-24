/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 11:58:25 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/24 17:14:19 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	*set_grid_size(char *str, t_fill *infos)
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
	char **grid;

	set_grid_size(infos->currentline, infos);

	while ()

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
