/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 16:38:12 by mbriffau          #+#    #+#             */
/*   Updated: 2018/01/30 02:21:49 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		parse_comment(t_lem *l)
{
	while ((l->lmap[l->i][0] == '#' && (l->lmap[l->i][1] != '#' ||
		l->lmap[l->i][2] == '#')) || ((l->lmap[l->i][0] == '#' &&
		l->lmap[l->i][1] == '#') && (ft_strcmp(&l->lmap[l->i][2], "start")
			|| ft_strcmp(&l->lmap[l->i][2], "end"))))
		l->i++;
	return (1);
}

int		search_sharp(t_lem *l)
{
	int n;

	n = 0;
	n += (l->lmap[l->i][0] == '#');
	n += (n ? (l->lmap[l->i][1] == '#'): 0);
	return (n);
}
