/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 13:20:07 by mfonteni          #+#    #+#             */
/*   Updated: 2018/02/19 18:34:28 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_fill	*structnew(char player)
{
	t_fill *new;

	if (!(new = (t_fill*)malloc(sizeof(t_fill))))
		return (NULL);
	new->grid = NULL;
	new->heatmap = NULL;
	new->currentline = NULL;
	new->player = player;
	new->gridsize.x = -1;
	new->gridsize.y = -1;
	new->piecesize.x = -1;
	new->piecesize.y = -1;
	new->place.y = 0;
	new->place.x = 0;
	new->currentpiece = NULL;
	new->overflow = 0;
	return (new);
}

int		*newarray(int size)
{
	int *array;

	if (!(array = (int*)malloc(sizeof(int) * size)))
		return (NULL);
	while (size)
		array[--size] = 0;
	return (array);
}

int		**new_twodim_array(int size)
{
	int **array;

	if (!(array = (int**)malloc(sizeof(int*) * size)))
		return (NULL);
	while (size)
		array[--size] = NULL;
	return (array);
}

char	**init_piece(int size)
{
	char **new;

	if (!(new = (char**)malloc(sizeof(char*) * size)))
		return (NULL);
	while (size)
		new[--size] = NULL;
	return (new);
}

void	structdel(t_fill *struc)
{
	int line;

	line = 0;
	ft_memdel((void**)&struc->currentline);
	while (line < struc->gridsize.y && struc->grid[line])
		ft_memdel((void**)&struc->grid[line++]);
	ft_memdel((void**)&struc->grid);
	line = -1;
//	while (struc->heatmap[++line])
//		ft_memdel((void**)&struc->heatmap[line]);
	ft_memdel((void**)&struc->heatmap);
	line = -1;
//	while (struc->currentpiece[++line])
//		ft_memdel((void**)&struc->currentpiece[line]);
	ft_memdel((void**)&struc->currentpiece);
	ft_memdel((void**)&struc);
}
