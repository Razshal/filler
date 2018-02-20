/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_array_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 11:43:44 by mfonteni          #+#    #+#             */
/*   Updated: 2018/02/20 11:43:45 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	*fill_array_lines(t_fill *infos, char *dst, const char *src)
{
	int count;

	count = 0;
	while (src[count] != '\0')
	{
		if (dst[count] == '.' && src[count] == ENNEMYCHAR)
			dst[count] = ENNEMYPOSCHAR;
		else
			dst[count] = src[count];
		count++;
	}
	dst[count] = '\0';
	return (dst);
}
