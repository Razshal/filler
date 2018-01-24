/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_types.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 19:07:24 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/22 14:50:15 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*pointer(t_plist *list)
{
	list->flag[0] = '#';
	list->flag[1] = '\0';
	return (ft_max_itoabase(16, (unsigned long)list->arg, 0));
}

static int	whatbaseisit(t_plist *list)
{
	if (list->type == 'x' || list->type == 'X' || list->type == 'p')
		return (16);
	else if (list->type == 'o')
		return (8);
	return (10);
}

static int	checkifnull(t_plist *list)
{
	if (list->type == 'o' && ft_strchr(list->flag, '#') && list->arg == 0)
		return (0);
	if (list->precision == 0)
		return (1);
	return (0);
}

char		*printf_type_d(t_plist *list)
{
	if (list->arg == 0)
		return (checkifnull(list) ? NULL : ft_max_itoabase(10, 0, 0));
	else if (check_hconv(list))
		return (ft_max_itoabase(10, (short)list->arg, 0));
	else if (list->length[0] == 'h' && list->length[1] == 'h')
		return (ft_max_itoabase(10, (char)list->arg, 0));
	else if (check_lconv(list) || list->type == 'D')
		return (ft_max_itoabase(10, (long)list->arg, 0));
	else if (list->length[0] == 'l' && list->length[1] == 'l')
		return (ft_max_itoabase(10, (long long)list->arg, 0));
	else if (list->length[0] == 'j')
		return (ft_max_itoabase(10, (intmax_t)list->arg, 0));
	else if (list->length[0] == 'z')
		return (ft_max_itoabase(10, (size_t)list->arg, 0));
	else if (!(list->length[0]) && !(list->type == 'D'))
		return (ft_max_itoabase(10, (int)list->arg, 0));
	return (NULL);
}

char		*printf_type_unsigned(t_plist *list)
{
	int base;
	int uppercase;

	uppercase = (list->type == 'X' ? 1 : 0);
	base = whatbaseisit(list);
	if (list->arg == 0)
		return (checkifnull(list) ? NULL : ft_umax_itoabase(10, 0, 0));
	else if (list->type == 'p')
		return (pointer(list));
	else if (check_hconv(list))
		return (ft_umax_itoabase(base, (unsigned short)list->arg, uppercase));
	else if (list->length[0] == 'h' && list->length[1] == 'h')
		return (ft_umax_itoabase(base, (unsigned char)list->arg, uppercase));
	else if (check_lconv(list) || list->type == 'D')
		return (ft_umax_itoabase(base, (unsigned long)list->arg, uppercase));
	else if (list->length[0] == 'l' && list->length[1] == 'l')
		return (ft_umax_itoabase(base,
					(unsigned long long)list->arg, uppercase));
	else if (list->length[0] == 'j')
		return (ft_umax_itoabase(base, (uintmax_t)list->arg, uppercase));
	else if (list->length[0] == 'z')
		return (ft_umax_itoabase(base, (size_t)list->arg, uppercase));
	else if (!(list->length[0]))
		return (ft_umax_itoabase(base, (unsigned int)list->arg, uppercase));
	return (NULL);
}
