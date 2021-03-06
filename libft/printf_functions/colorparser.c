/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorparser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 19:04:37 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/23 13:37:45 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <unistd.h>

static char	*get_colorcode(char *str)
{
	char *s;

	s = &str[1];
	if (!ft_strncmp(s, "RED}", 4))
		return (ft_noleaks_strjoin("\x1b[31m", NULL));
	if (!ft_strncmp(s, "GREEN}", 6))
		return (ft_noleaks_strjoin("\x1b[32m", NULL));
	if (!ft_strncmp(s, "YELLOW}", 7))
		return (ft_noleaks_strjoin("\x1b[33m", NULL));
	if (!ft_strncmp(s, "BLUE}", 5))
		return (ft_noleaks_strjoin("\x1b[34m", NULL));
	if (!ft_strncmp(s, "MAGENTA}", 8))
		return (ft_noleaks_strjoin("\x1b[35m", NULL));
	if (!ft_strncmp(s, "CYAN}", 5))
		return (ft_noleaks_strjoin("\x1b[36m", NULL));
	if (!ft_strncmp(s, "EOC}", 4))
		return (ft_noleaks_strjoin("\x1b[0m", NULL));
	return (NULL);
}

int			colorprinter(char *str)
{
	int		count;
	char	*colorcode;
	int		written;

	count = 0;
	colorcode = NULL;
	written = 0;
	if (ft_strchr(str, '{') && get_colorcode(ft_strchr(str, '{')))
	{
		while (str[count])
		{
			if (!(str[count] == '{') && (++written))
				ft_putchar(str[count++]);
			else if ((colorcode = get_colorcode(&str[count])))
			{
				written += write(1, colorcode, ft_strlen(colorcode));
				while (str[count] && str[count - 1] != '}')
					count++;
			}
		}
	}
	else
		ft_putstr(str);
	return (written ? written : ft_strlen(str));
}
