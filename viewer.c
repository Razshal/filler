/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 12:30:09 by mfonteni          #+#    #+#             */
/*   Updated: 2018/02/24 13:29:49 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include <unistd.h>

static void print_players(char *line)
{
	int count;

	count = 0;
	while (line[count])
	{
		if (line[count] == 'O')
			ft_printf("{RED}%c{EOC}", line[count]);
		else if (line[count] == 'o')
			ft_printf("{YELLOW}%c{EOC}", line[count]);
		else if (line[count] == 'X')
			ft_printf("{BLUE}%c{EOC}", line[count]);
		else if (line[count] == 'x')
			ft_printf("{CYAN}%c{EOC}", line[count]);
		else if (line[count] == '.')
			ft_putchar(line[count]);
		count++;
	}
	ft_putchar('\n');
}

static void print_spaces(void)
{
	int count;

	count = 0;
	while (count++ < 150)
		ft_putchar('\n');
}

static void print_score(int score_x, int score_o)
{
	ft_printf("{RED}Joueur O : %d{EOC}\n{BLUE}Joueur X : %d{EOC}\n",
			score_o, score_x);
}

int main (int argc, char **argv)
{
	int		pieces_x;
	int		pieces_o;
	char	*line;

	pieces_x = 0;
	pieces_o = 0;
	while (get_next_line(0, &line))
	{
		if (ft_strstr(line, "Plateau"))
		{
			usleep(argc > 1 ? ft_atoi(argv[1]) : 5000);
			print_spaces();
			print_score(pieces_x, pieces_o);
		}
		if (ft_isdigit(line[0]))
			print_players(line);
		pieces_x = ft_strchr(line, 'x') ? pieces_x + 1 : pieces_x;
		pieces_o = ft_strchr(line, 'o') ? pieces_o + 1 : pieces_o;
	}
}
