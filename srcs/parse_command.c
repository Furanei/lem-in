/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 16:38:12 by mbriffau          #+#    #+#             */
/*   Updated: 2018/02/02 05:12:35 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
					
int		parse_comment(t_lem *l)
{
	while ((l->lmap[l->i][0] == '#' && (l->lmap[l->i][1] != '#' ||
		l->lmap[l->i][2] == '#')))
		l->i++;
	return (1);
}

int		search_sharp(t_lem *l)
{
	int n;

	n = 0;
	if (l->lmap[l->i][0] == '#')
		n++;
	if (l->lmap[l->i][1] == '#')
		n++;
	return (n);
}

void	parse_order(t_lem *l)
{
	if (ft_strequ(&l->lmap[l->i][2], "start") && !(l->f & START))
		l->f += START + STARTEND;
	else if (ft_strequ(&l->lmap[l->i][2], "end") && !(l->f & END))
		l->f += END + STARTEND;
}