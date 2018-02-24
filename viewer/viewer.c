/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 12:30:09 by mfonteni          #+#    #+#             */
/*   Updated: 2018/02/24 18:27:24 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include <unistd.h>

static int	print_players(char *line, int ret)
{
	int count;

	count = 0;
	while (line[count])
	{
		if (line[count] == 'O')
			ft_printf("\e[41m  {EOC}");
		else if (line[count] == 'o')
			ft_printf("\e[43m  {EOC}");
		else if (line[count] == 'X')
			ft_printf("\e[44m  {EOC}");
		else if (line[count] == 'x')
			ft_printf("\e[46m  {EOC}");
		else if (line[count] == '.')
			ft_printf("%C ", L'▢');
		count++;
	}
	ft_putchar('\n');
	if (ft_strchr(line, 'o'))
		return (2);
	else if (ft_strchr(line, 'x'))
		return (3);
	return (ret);
}

static void	print_newlines(int howmany)
{
	int count;

	count = 0;
	while (count++ < howmany)
		ft_putchar('\n');
}

static void	print_score(int score_o, int score_x)
{
	ft_printf("\e[41mPlayer O : %d{EOC}\n\e[44mPlayer X : %d{EOC}\n\n",
			score_o, score_x);
}

static void	print_result(int score_o, int score_x)
{
	print_newlines(5);
	if (score_o > score_x)
		ft_printf("\e[41mVictory for Player O | %d vs {EOC}\e[44m%d{EOC}\n",
				score_o, score_x);
	if (score_x > score_o)
		ft_printf("\e[44mVictory for Player X | %d{EOC} vs \e[41m%d{EOC}\n",
				score_x, score_o);
	if (score_o == score_x)
		ft_printf("\e[44mMATCH NULL{EOC}\n");
}

int			main(int argc, char **argv)
{
	int		pieces_x;
	int		pieces_o;
	char	*line;
	int		ret;

	pieces_x = 0;
	pieces_o = 0;
	while (get_next_line(0, &line))
	{
		if (ft_strstr(line, "Plateau"))
		{
			if ((ft_strstr(argv[1], "-q")
					|| (argc > 2 && ft_strstr(argv[2], "-q")))
					&& (pieces_x + 10 < pieces_o || pieces_o + 10 < pieces_x))
				break ;
			usleep(argc > 1 && ft_atoi(argv[1]) > 0 ? ft_atoi(argv[1]) : 50000);
			print_newlines(150);
			print_score((pieces_o += (ret == 2)), (pieces_x += (ret == 3)));
		}
		if (ft_isdigit(line[0]))
			ret = print_players(line, ret);
		ft_memdel((void**)&line);
	}
	ft_memdel((void**)&line);
	print_result(pieces_o, pieces_x);
}
