/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 16:34:11 by mbriffau          #+#    #+#             */
/*   Updated: 2018/01/22 04:41:02 by mbriffau         ###   ########.fr       */
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
	l->room_list = NULL;
	return(l);
}

int 	parse_room(t_lem *l)
{
	if (l->s[0] == 'L')
		ft_error_info(INFO, "room name(L)");
	else if ((room_count_word(l->s, ' ')))
	{
		parse2_room(&*l , 0);
	}
	else if (search_sharp(l) == 2)
	{
		l->f += STARTEND;
		parse2_room(&*l, 1);
	}
	else if (search_sharp(l))
	{
		gne(&*l);
	} 
	else
		ft_error_info(INFO, "room");
	return (gne(&*l));
}
