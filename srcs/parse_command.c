/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 16:38:12 by mbriffau          #+#    #+#             */
/*   Updated: 2018/03/01 20:12:18 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		parse_comment(t_lem *l)
{
	if (l->lmap[l->i] == 0)
		ft_error("ERROR");
	while (l->lmap[l->i] && (l->lmap[l->i][0] == '#' &&
		(l->lmap[l->i][1] != '#' || l->lmap[l->i][2] == '#')))
	{
		l->i++;
	}
	if (l->lmap[l->i] == NULL)
		return (0);
	return (1);
}

int		search_sharp(t_lem *l)
{
	int	n;

	n = 0;
	if (l->lmap[l->i][0] == '#')
		n++;
	if (l->lmap[l->i][1] == '#')
		n++;
	return (n);
}

void	parse_order(t_lem *l, char *s)
{
	if (ft_strequ(&s[2], "start") && !(l->f & START))
		l->f += START + NEXTSTART;
	else if (ft_strequ(&s[2], "end") && !(l->f & END))
		l->f += END + NEXTEND;
}
