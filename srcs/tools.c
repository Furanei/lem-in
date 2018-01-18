/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:54:23 by mbriffau          #+#    #+#             */
/*   Updated: 2018/01/18 03:07:44 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_lem	*init_struct(t_lem *l)
{
	l->f = 0;
	l->ant = 0;
	l->start = 0;
	l->end = 0;
	l->start_name = NULL;
	l->end_name = NULL;
	l->room_list = NULL;
	l->map = NULL;

	return(l);
}

void	saved_map(t_lem *l)
{
	if (l->map)
		l->map = ft_strnjoinfree(l->map, l->s, ft_strlen(l->s), 'B');
	else
	{
		l->map = ft_strdup(l->s);
		free(l->s);
	}
}

int 	gne(t_lem *l)
{
	saved_map(&*l);
	return (get_next_line(0, &l->s));
}

// void	free_data()
// {
	
// }