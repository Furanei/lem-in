/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 16:49:08 by mbriffau          #+#    #+#             */
/*   Updated: 2018/01/27 02:24:32 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

// void	add_pipe(t_room *r1, t_room *r2)
// {
// 	t_room		*tmp;

// 	tmp = *r1->pipe;
// 	while (r1->pipe[0])
// 	{

// 	}
// }
t_room	*get_room(char *s, t_room *r, int i)
{
	while (r && (ft_strncmp(s, (r)->name, i) != 0))
		r = r->next;
	return(r);
}

void	parse_pipe(t_lem *l)
{
	int 		j;
	int			i;
	t_room		*r1;
	t_room		*r2;
	j = 0;
	parse_comment(&*l);
	i = ft_strlen_c(l->s, '-');
	printf("%s[i=%d\n", l->s, i);
	r1 = *l->room_list;
	r2 = *l->room_list;
	(r1 = get_room(&l->s[j], &*r1, i)) == NULL ? ft_error_info(INFO, "room1") : 0;
	j =  next_word(&*l, i, '-');
	(r2 = get_room(&l->s[j], &*r2, i)) == NULL ? ft_error_info(INFO, l->s) : 0;
	r1->pipe[r1->npipe] = r2;
	r1->npipe++;
	r2->pipe[r2->npipe] = r1;
	r2->npipe++;
}
