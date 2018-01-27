/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:54:23 by mbriffau          #+#    #+#             */
/*   Updated: 2018/01/27 02:23:04 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_lem	*init_struct(t_lem *l)
{
	l->f = 0;
	l->ant = 0;
	l->start = 0;
	l->end = 0;
	l->nline = 0;
	l->index = 0;
	l->start_name = NULL;
	l->end_name = NULL;
	*l->room_list = NULL;
	l->nb_room = 0;
	return(l);
}

int		next_line(t_lem *l)
{
	l->index += l->n;
	l->index += (l->index ? 1 : 0);
	l->n = ft_strlen_c(&l->map[l->index], '\n');
	// printf("[%d-%d]%d]%s\n", l->n, l->index, (int)ft_strlen(&l->map[l->index]), &l->map[l->index]);
	l->s = ft_strndup(&l->map[l->index], l->n);
	return (1);
}

int 	gne(t_lem *l)
{
	if (l->nline)
	{
		l->map = ft_strnjoinfree(l->map, "\n", ft_strlen(l->s), 'L');
		l->map = ft_strnjoinfree(l->map, l->s, ft_strlen(l->s), 'B');
	}
	else
	{
		l->map = ft_strdup(l->s);
		free(l->s);
	}
	return(get_next_line(0, &l->s));
}
