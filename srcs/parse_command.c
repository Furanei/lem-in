/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 16:38:12 by mbriffau          #+#    #+#             */
/*   Updated: 2018/01/24 15:59:34 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		parse_comment(t_lem *l)
{
	while ((l->s[0] == '#' && (l->s[1] != '#' || l->s[2] == '#')) ||
		((l->s[0] == '#' && l->s[1] == '#') && (ft_strcmp(&l->s[2], "start") || ft_strcmp(&l->s[2], "end"))))
		next_line(&*l);
	return (1);
}

int		search_sharp(t_lem *l)
{
	int n;

	n = 0;
	n += (l->s[0] == '#');
	n += (n ? (l->s[1] == '#'): 0);
	return (n);
}
