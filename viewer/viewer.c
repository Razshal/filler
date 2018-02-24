/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 12:30:09 by mfonteni          #+#    #+#             */
/*   Updated: 2018/02/24 16:48:14 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include <unistd.h>

static void	print_players(char *line)
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
	ft_printf("\e[41mJoueur O : %d{EOC}\n\e[44mJoueur X : %d{EOC}\n\n",
			score_o, score_x);
}

int			main(int argc, char **argv)
{
	int		pieces_x;
	int		pieces_o;
	int		done;
	char	*line;

	pieces_x = 0;
	pieces_o = 0;
	done = 0;
	while (get_next_line(0, &line))
	{
		if (ft_strstr(line, "Plateau"))
		{
			usleep(argc > 1 ? ft_atoi(argv[1]) : 50000);
			print_newlines(150);
			print_score(pieces_o, pieces_x);
		}
		if (ft_isdigit(line[0]))
			print_players(line);
		pieces_o += !(!ft_strstr(line, "<got (O)"));
		pieces_o -= pieces_o < pieces_x && !done++;
		pieces_x += !(!ft_strstr(line, "<got (X)"));
		pieces_x -= pieces_x < pieces_o && !done++;
		ft_memdel((void**)&line);
	}
}
